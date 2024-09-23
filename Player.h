#pragma once
#include "Soldier.h"
#include "MathUtils.h"
#include "Event.h"
#include<vector>
#include <thread>
#include<chrono>
class Player
{
public:
	Player(int initialArmySize, int playerId, PlayerSide playerSide);
	Player() = delete;
	~Player();

	std::shared_ptr<Soldier> GetSoldier(int index);
	int GetArmySize();
	int GetPlayerId();
	int GetIdleSoldierCount();
	PlayerSide GetPlayerSide();
	void IncrementIdleSoldierCount();
	void ResetIdleSoldierCount();
	void AddSoldier(std::shared_ptr<Soldier> soldier);
	void KillSoldier(std::shared_ptr<Soldier> dyingSoldier);
	void MoveArmy(GridCoordinates boundary);
	void SetDefeated();
	static void RegisterEventHandler(EventHandler& handler);
	bool IsDefeated();

private:
	int _armySize = 0;
	int _playerId = -1;
	int _idleSoldierCounter = 0;
	bool _isPlayerDefeated = false;
	PlayerSide _playerSide = NoSide;
	std::vector<std::shared_ptr<Soldier>> _soldiers;
	static Event* PlayerEvent;
};