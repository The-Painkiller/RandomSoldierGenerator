#pragma once
#include<cstdlib>
#include"PlayerManager.h"
#include"GridManager.h"
#include "SoldierFactory.h"
#include "CombatManager.h"

class GameManager
{
public:
	GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers);
	GameManager() = delete;
	
	~GameManager();

	void Initialize();
	void AddNewPlayer();
	void BeginBattle();
	Player& GetPlayer(int index);
	int GetCurrentPlayerCount();

private:
	PlayerManager* _playerManager = nullptr;
	GridManager* _gridManager = nullptr;
	CombatManager* _combatManager = nullptr;
	SoldierFactory* _soldierFactory = new SoldierFactory();
	const GridCoordinates DefaultGridSize = { 100, 100 };
	
	GridCoordinates GetRandomPosition();
};