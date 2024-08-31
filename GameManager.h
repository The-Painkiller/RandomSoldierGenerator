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
#include "PropFactory.h"
#include "Graphics2D.h"

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
	PropFactory* _propFactory = new PropFactory();
	PropManager* _propManager = new PropManager();
	Graphics2D* _graphics = new Graphics2D();

	bool _isGameOver = false;
	
	const GridCoordinates DefaultGridSize = { 50, 50 };
	const int DefaultPropCountAtStart = 20;

	const Color ColorPlayer01 = BLUE;
	const Color ColorPlayer02 = RED;
	const Color ColorProp = MAGENTA;
	
	GridCoordinates GetRandomPosition(PlayerSide playerSide);
	void PlaceSoldiers();
	void PlaceProps();
	void RefreshGridPositions();
	void ConsumePropByType(int propIndex, int playerIndex, int soldierIndex);
};