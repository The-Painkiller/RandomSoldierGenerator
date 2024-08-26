#include "GameManager.h"

GameManager::GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers)
{
	_playerManager = new PlayerManager(defaultPlayerCount, defaultNumberOfSoldiers);
	_gridManager = new GridManager(DefaultGridSize);
	_combatManager = new CombatManager();
}

GameManager::~GameManager()
{
	delete _playerManager;
	_playerManager = nullptr;

	delete _gridManager;
	_gridManager = nullptr;

	delete _soldierFactory;
	_soldierFactory = nullptr;

	delete _combatManager;
	_combatManager = nullptr;
}

void GameManager::Initialize()
{
	PlaceSoldiers();
	PlaceProps();
	_combatManager->RegisterEventHandler(this);
}

void GameManager::BeginBattle()
{
	_combatManager->Initialize(_playerManager->GetPlayers(), _playerManager->GetPlayerCount());
	
	while (!_playerManager->AreAllPlayersIdle() && !_isGameOver)
	{
		//Soldiers prioritize attacking, then collecting props before moving to next position.
		PlayAttackTurnCycle();
		PlayPropCollectionCycle();
		PlayMovementCycle();
	}
}

void GameManager::PlayAttackTurnCycle()
{
	if (_isGameOver)
	{
		return;
	}

	GameLogger::LogText("---Attack Cycle---");
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		if (!_playerManager->GetPlayer(i).IsDefeated())
		{
			_combatManager->SetCurrentTurn(i);
			_combatManager->BeginCurrentAttack();
			std::this_thread::sleep_for(std::chrono::milliseconds(0));
		}
		else
		{
			_isGameOver = true;
			break;
		}
	}
}

void GameManager::PlayPropCollectionCycle()
{
	if (_isGameOver)
	{
		return;
	}

	GameLogger::LogText("---Prop Cycle---");

	if (_propManager->GetPropsCount() <= 0)
	{
		GameLogger::LogText("All props consumed, no new props collected...");
		return;
	}
	
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		for (int j = 0; j < _playerManager->GetPlayer(i).GetArmySize(); j++)
		{
			for (int k = 0; k < _propManager->GetPropsCount(); k++)
			{
				int soldierPosX = _playerManager->GetPlayer(i).GetSoldier(j).GetPosition().X;
				int soldierPosY = _playerManager->GetPlayer(i).GetSoldier(j).GetPosition().Y;
				int soldierRange = _playerManager->GetPlayer(i).GetSoldier(j).GetAttackRange();

				int propPosX = _propManager->GetProp(k)->GetPosition().X;
				int propPosY = _propManager->GetProp(k)->GetPosition().Y;

				if (MathUtils::EuclideanDistance(soldierPosX, soldierPosY, propPosX, propPosY) <= soldierRange)
				{
					switch (_propManager->GetProp(k)->GetPropType())
					{
					case ArmourType:
					{
						_playerManager->GetPlayer(i).GetSoldier(j).SetArmour((PropArmour*)_propManager->GetProp(k));
					}
						break;

					case HealthBoostType:
					{
						int healthBoost = ((PropHealthBoost*)_propManager->GetProp(k))->GetBoostAmount();
						int health = _playerManager->GetPlayer(i).GetSoldier(j).GetHealth() + healthBoost;

						_playerManager->GetPlayer(i).GetSoldier(j).SetHealth(health, false);
					}
						break;

					case AttackBoostType:
					{
						int attackBoost = ((PropAttackBoost*)_propManager->GetProp(k))->GetBoostAmount();
						int damage = _playerManager->GetPlayer(i).GetSoldier(j).GetDamage() + attackBoost;

						_playerManager->GetPlayer(i).GetSoldier(j).SetDamage(damage);
					}
						break;
					}

					GameLogger::LogPropConsumption(i, j, _propManager->GetProp(k));
					_propManager->RemoveProp(k);
					break;
				}

			}
		}
	}

	RefreshGridPositions();
}

void GameManager::PlayMovementCycle()
{
	if (_isGameOver)
	{
		return;
	}

	GameLogger::LogText("---Movement Cycle---");
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		_playerManager->GetPlayer(i).MoveArmy(DefaultGridSize);
	}

	LogPlayerArmies();
}

void GameManager::LogPlayerArmies()
{
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		GameLogger::LogPlayerArmy(_playerManager->GetPlayer(i));
	}
}

void GameManager::HandleEvent(GameEvent type)
{
	switch (type)
	{
	case GameOver:
		_isGameOver = true;
		break;
	}
}

Player& GameManager::GetPlayer(int index)
{
	return _playerManager->GetPlayer(index);
}

int GameManager::GetCurrentPlayerCount()
{
	return _playerManager->GetPlayerCount();
}

GridCoordinates GameManager::GetRandomPosition(PlayerSide playerSide)
{
	int posX = 0;
	int posY = 0;

	switch (playerSide)
	{
		case Left:
			while (_gridManager->IsPositionOccupied({ posX, posY }))
			{
				posX = rand() % _playerManager->GetDefaultNumberOfSoldiers();
				posY = rand() % DefaultGridSize.Y;
			}
			break;

		case Right:
			while (_gridManager->IsPositionOccupied({ posX, posY }))
			{
				posX = rand() % _playerManager->GetDefaultNumberOfSoldiers() + (DefaultGridSize.X - _playerManager->GetDefaultNumberOfSoldiers());
				posY = rand() % DefaultGridSize.Y;
			}
			break;

		case NoSide:
			while (_gridManager->IsPositionOccupied({ posX, posY }))
			{
				posX = rand() % DefaultGridSize.X;
				posY = rand() % DefaultGridSize.Y;
			}
			break;
	}
	return {posX, posY};
}

void GameManager::PlaceSoldiers()
{
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		for (int j = 0; j < _playerManager->GetDefaultNumberOfSoldiers(); j++)
		{
			int randomSoldierId = rand() % (SoldierType::None - 1) + 1;
			GridCoordinates soldierPosition = GetRandomPosition(_playerManager->GetPlayer(i).GetPlayerSide());
			_playerManager->AddSoldierForPlayer(i, _soldierFactory->CreateSoldier((SoldierType)randomSoldierId, soldierPosition));
			_gridManager->OccupyPosition(soldierPosition);
		}
	}
}

void GameManager::PlaceProps()
{
	for (int i = 0; i < DefaultPropCountAtStart; i++)
	{
		GridCoordinates propPosition = GetRandomPosition(NoSide);

		PropType randomPropType = (PropType)MathUtils::Random(1, 4);
		_propManager->AddProp(_propFactory->CreateProp(randomPropType, propPosition));
		_gridManager->OccupyPosition(propPosition);
	}
}

void GameManager::RefreshGridPositions()
{
	_gridManager->ClearPositions();

	//position of remaining props.
	for (int i = 0; i < _propManager->GetPropsCount(); i++)
	{
		if (_propManager->GetProp(i) != nullptr)
		{
			GridCoordinates pos = _propManager->GetProp(i)->GetPosition();

			_gridManager->OccupyPosition(pos);
		}
	}

	//position of all the remaining attacking & defending soldiers.
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		for (int j = 0; j < _playerManager->GetPlayer(i).GetArmySize(); j++)
		{
			GridCoordinates pos = _playerManager->GetPlayer(i).GetSoldier(j).GetPosition();

			_gridManager->OccupyPosition(pos);
		}
	}
}
