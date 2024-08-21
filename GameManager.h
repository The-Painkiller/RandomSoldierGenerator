#pragma once
#include<cstdlib>
#include<thread>
#include<chrono>
#include"PlayerManager.h"
#include"GridManager.h"
#include "SoldierFactory.h"
#include "CombatManager.h"
#include "GameLogger.h"

class GameManager
{
public:
	GameManager(const int defaultPlayerCount, const int defaultNumberOfSoldiers);
	GameManager() = delete;
	
	~GameManager();

	void Initialize();
	void BeginBattle();
	void PlayAttackTurnCycle();
	void PlayPropCollectionCycle();
	void PlayMovementCycle();
	void LogPlayerArmies();
	Player& GetPlayer(int index);
	int GetCurrentPlayerCount();

private:
	PlayerManager* _playerManager = nullptr;
	GridManager* _gridManager = nullptr;
	CombatManager* _combatManager = nullptr;
	SoldierFactory* _soldierFactory = new SoldierFactory();
	const GridCoordinates DefaultGridSize = { 100, 100 };
	const int DefaultPropCountAtStart = 20;
	
	GridCoordinates GetRandomPosition(PlayerSide playerSide);
};