#pragma once
#include "Soldier.h"
#include "MathUtils.h"
#include<vector>
class Player
{
public:
	Player(int initialArmySize, int playerId, PlayerSide playerSide);
	Player() = delete;
	~Player();

	Soldier& GetSoldier(int index);
	int GetArmySize();
	int GetPlayerId();
	int GetIdleSoldierCount();
	PlayerSide GetPlayerSide();
	void IncrementIdleSoldierCount();
	void ResetIdleSoldierCount();
	void AddSoldier(Soldier* soldier);
	void KillSoldier(Soldier* dyingSoldier);
	void MoveArmy(GridCoordinates boundary);

private:
	int _armySize = 0;
	int _playerId = -1;
	int _idleSoldierCounter = 0;
	PlayerSide _playerSide = NoSide;
	std::vector<Soldier*> _soldiers;
};