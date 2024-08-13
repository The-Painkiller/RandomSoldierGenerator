#pragma once
#include "Soldier.h"
#include<vector>
class Player
{
public:
	Player(int initialArmySize, int playerId);
	Player() = delete;
	~Player();

	void AddSoldier(Soldier* soldier);
	Soldier* GetSoldier(int index);
	int GetArmySize();
	int GetPlayerId();

private:
	int _armySize = 0;
	int _playerId = -1;
	std::vector<Soldier*> _soldiers;
};

