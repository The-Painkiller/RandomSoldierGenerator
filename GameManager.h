#pragma once
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

	void HandleEvent(GameEvent type, const GridCoordinates arg1, const int arg2) override;
	void HandleEvent(GameEvent type, const GridCoordinates prevPos, const GridCoordinates newPos, const int playerID) override;

	Player& GetPlayer(int index);
	int GetCurrentPlayerCount();

private:
	unique_ptr<PlayerManager> _playerManager = nullptr;
	unique_ptr<GridManager> _gridManager = nullptr;
	unique_ptr<CombatManager> _combatManager = nullptr;
	unique_ptr<SoldierFactory> _soldierFactory = unique_ptr<SoldierFactory>(new SoldierFactory());
	unique_ptr<PropFactory> _propFactory = unique_ptr<PropFactory>(new PropFactory());
	unique_ptr<PropManager> _propManager = unique_ptr<PropManager>(new PropManager());
	unique_ptr<Graphics2D> _graphics = unique_ptr<Graphics2D>(new Graphics2D());

	bool _isGameOver = false;
	
	const GridCoordinates DefaultGridSize = { 50, 50 };
	const int DefaultPropCountAtStart = 20;

	const Color ColorPlayer01 = BLUE;
	const Color ColorHurtPlayer01 = SKYBLUE;
	const Color ColorPlayer02 = RED;
	const Color ColorHurtPlayer02 = PINK;
	const Color ColorProp = ORANGE;
	
	GridCoordinates GetRandomPosition(PlayerSide playerSide);
	void PlaceSoldiers();
	void PlaceProps();
	void RefreshGridPositions();
	void ConsumePropByType(int propIndex, int playerIndex, int soldierIndex);
};