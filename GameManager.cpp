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

void GameManager::BeginBattle()
{
	_combatManager->Initialize(_playerManager->GetPlayers(), _playerManager->GetPlayerCount());
	
	while (!_playerManager->AreAllPlayersIdle())
	{
		PlayAttackTurnCycle();
		PlayMovementCycle();
	}
}

void GameManager::PlayAttackTurnCycle()
{
	GameLogger::LogText("---Attack Cycle---");
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		_combatManager->SetCurrentTurn(i);
		_combatManager->BeginCurrentAttack();
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
}

void GameManager::PlayPropCollectionCycle()
{
}

void GameManager::PlayMovementCycle()
{
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
	}
	return {posX, posY};
}