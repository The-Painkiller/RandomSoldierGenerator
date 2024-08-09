#pragma once
#include<cstdlib>
#include"PlayerManager.h"
#include"GridManager.h"
#include "SoldierFactory.h"

class GameManager
{
public:
	GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers);
	GameManager() = delete;
	
	~GameManager();

	void Initialize();
	void AddNewPlayer();
	Player& GetPlayer(int index);
	int GetCurrentPlayerCount();

private:
	PlayerManager* _playerManager = nullptr;
	GridManager* _gridManager = nullptr;
	SoldierFactory* _soldierFactory = new SoldierFactory();
	const GridCoordinates DefaultGridSize = { 1000, 1000 };
	
	GridCoordinates GetRandomPosition();
};