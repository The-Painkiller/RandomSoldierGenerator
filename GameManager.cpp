#include "GameManager.h"

GameManager::GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers)
{
	_playerManager = unique_ptr<PlayerManager>(new PlayerManager(defaultPlayerCount, defaultNumberOfSoldiers));
	_gridManager = unique_ptr<GridManager>(new GridManager(DefaultGridSize));
	_combatManager = unique_ptr<CombatManager>(new CombatManager());
}

GameManager::~GameManager()
{
	_playerManager = nullptr;
	_gridManager = nullptr;
	_soldierFactory = nullptr;
	_combatManager = nullptr;
	_propFactory = nullptr;
	_propManager = nullptr;
	_graphics = nullptr;
}

void GameManager::Initialize()
{
	PlaceSoldiers();
	PlaceProps();
	_combatManager->RegisterEventHandler(*this);
	Player::RegisterEventHandler(*this);

	_graphics->Initialize(_gridManager->GetGridSize());
	RefreshGridPositions();
}

void GameManager::BeginBattle()
{
	_combatManager->Initialize(_playerManager->GetPlayers(), _playerManager->GetPlayerCount());

	while (!_graphics->ShouldGraphicsWindowClose())
	{
		if (!_playerManager->AreAllPlayersIdle()
			&& !_isGameOver)
		{
			_graphics->WindowLoop();
			PlayAttackTurnCycle();
			PlayPropCollectionCycle();
			PlayMovementCycle();
			RefreshGridPositions();
		}
	}

	_graphics->CloseGraphicsWindow();
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
			std::this_thread::sleep_for(std::chrono::milliseconds(ThreadSleepTime));
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
				int soldierPosX = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetPosition().X;
				int soldierPosY = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetPosition().Y;
				int soldierRange = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetAttackRange();

				int propPosX = _propManager->GetProp(k).GetPosition().X;
				int propPosY = _propManager->GetProp(k).GetPosition().Y;

				if (MathUtils::EuclideanDistance(soldierPosX, soldierPosY, propPosX, propPosY) <= soldierRange)
				{
					ConsumePropByType(k, i, j);

					GameLogger::LogPropConsumption(i, j, &_propManager->GetProp(k));
					
					_graphics->DrawObject(_propManager->GetProp(k).GetPosition(), LIGHTGRAY);
					
					_propManager->RemoveProp(k);

					break;
				}
			}
		}
	}
}

void GameManager::ConsumePropByType(int propIndex, int playerIndex, int soldierIndex)
{
	switch (_propManager->GetProp(propIndex).GetPropType())
	{
	case ArmourType:
	{
		_playerManager->GetPlayer(playerIndex).GetSoldier(soldierIndex).get()->SetArmour((PropArmour&)_propManager->GetProp(propIndex));
	}
	break;

	case HealthBoostType:
	{
		int healthBoost = ((PropHealthBoost&)_propManager->GetProp(propIndex)).GetBoostAmount();
		int health = _playerManager->GetPlayer(playerIndex).GetSoldier(soldierIndex).get()->GetHealth() + healthBoost;

		_playerManager->GetPlayer(playerIndex).GetSoldier(soldierIndex).get()->SetHealth(health, false);
	}
	break;

	case AttackBoostType:
	{
		int attackBoost = ((PropAttackBoost&)_propManager->GetProp(propIndex)).GetBoostAmount();
		int damage = _playerManager->GetPlayer(playerIndex).GetSoldier(soldierIndex).get()->GetDamage() + attackBoost;

		_playerManager->GetPlayer(playerIndex).GetSoldier(soldierIndex).get()->SetDamage(damage);
	}
	break;
	}
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
		//std::this_thread::sleep_for(std::chrono::milliseconds(ThreadSleepTime));
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

void GameManager::HandleEvent(GameEvent type, const GridCoordinates arg1, const int arg2)
{
	switch (type)
	{
	case GameOver:
		_isGameOver = true;
		if (arg2 == 0)
		{
			_graphics->DrawGraphicsText("Player02 Wins!");
		}
		else
		{
			_graphics->DrawGraphicsText("Player01 Wins!");
		}
		break;

	case SoldierDeath:
		_graphics->DrawObject(arg1, LIGHTGRAY);
		break;

	case SoldierHurt:
		_graphics->DrawObject(arg1, arg2 == 0 ? ColorHurtPlayer01 : ColorHurtPlayer02);
		break;
	}
}

void GameManager::HandleEvent(GameEvent type, const GridCoordinates prevPos, const GridCoordinates newPos, const int playerID)
{
	switch (type)
	{
	case SoldierMove:
		_graphics->DrawObject(prevPos, LIGHTGRAY);
		_graphics->DrawObject(newPos, playerID == 0 ? ColorPlayer01 : ColorPlayer02);
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
	_graphics->ResetCellData();
	//position of remaining props.
	for (int i = 0; i < _propManager->GetPropsCount(); i++)
	{
		GridCoordinates pos = _propManager->GetProp(i).GetPosition();
		_gridManager->OccupyPosition(pos);
		_graphics->SetCellData(pos, ColorProp);
	}

	//position of all the remaining attacking & defending soldiers.
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		for (int j = 0; j < _playerManager->GetPlayer(i).GetArmySize(); j++)
		{
			GridCoordinates pos = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetPosition();
			_gridManager->OccupyPosition(pos);
			Color col;
			if (i == 0)
			{
				col = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetHealth() < _playerManager->GetPlayer(i).GetSoldier(j).get()->GetDefaultHealth() ? ColorHurtPlayer01 : ColorPlayer01;
			}
			else
			{
				col = _playerManager->GetPlayer(i).GetSoldier(j).get()->GetHealth() < _playerManager->GetPlayer(i).GetSoldier(j).get()->GetDefaultHealth() ? ColorHurtPlayer02 : ColorPlayer02;
			}

			_graphics->SetCellData(pos, col);
		}
	}
}
