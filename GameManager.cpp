#include "GameManager.h"

GameManager::GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers)
{
	_playerManager = new PlayerManager(defaultPlayerCount, defaultNumberOfSoldiers);
	_gridManager = new GridManager(DefaultGridSize);
}

GameManager::~GameManager()
{
	delete _playerManager;
	_playerManager = nullptr;

	delete _gridManager;
	_gridManager = nullptr;

	delete _soldierFactory;
	_soldierFactory = nullptr;
}

void GameManager::Initialize()
{
	for (int i = 0; i < _playerManager->GetPlayerCount(); i++)
	{
		for (int j = 0; j < _playerManager->GetSoldierCount(); j++)
		{
			int randomSoldierId = rand() % (SoldierType::None - 1) + 1;
			_playerManager->AddSoldierForPlayer(i, _soldierFactory->CreateSoldier((SoldierType)randomSoldierId, GetRandomPosition()));
		}
	}
}

void GameManager::AddNewPlayer()
{
	_playerManager->AddNewPlayer();
}

Player& GameManager::GetPlayer(int index)
{
	return *_playerManager->GetPlayer(index);
}

int GameManager::GetCurrentPlayerCount()
{
	return _playerManager->GetPlayerCount();
}

GridCoordinates GameManager::GetRandomPosition()
{
	int posX = rand() % DefaultGridSize.X;
	int posY = rand() % DefaultGridSize.Y;
	while (_gridManager->IsPositionOccupied({ posX, posY }))
	{
		posX = rand() % DefaultGridSize.X;
		posY = rand() % DefaultGridSize.Y;
	}

	return {posX, posY};
}
