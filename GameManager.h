#pragma once
#include<cstdlib>
#include<thread>
#include<chrono>
#include"PlayerManager.h"
#include"GridManager.h"
#include "SoldierFactory.h"
#include "CombatManager.h"
#include "GameLogger.h"
#include "PropManager.h"

class GameManager : public EventHandler
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

	void HandleEvent(GameEvent type) override;

	Player& GetPlayer(int index);
	int GetCurrentPlayerCount();

private:
	PlayerManager* _playerManager = nullptr;
	GridManager* _gridManager = nullptr;
	CombatManager* _combatManager = nullptr;
	SoldierFactory* _soldierFactory = new SoldierFactory();

	bool _isGameOver = false;
	
	const GridCoordinates DefaultGridSize = { 100, 100 };
	const int DefaultPropCountAtStart = 20;
	
	GridCoordinates GetRandomPosition(PlayerSide playerSide);
	void PlaceSoldiers();
	void PlaceProps();
};