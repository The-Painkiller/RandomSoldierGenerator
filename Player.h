#pragma once
#include "Soldier.h"
#include<vector>
class Player
{
public:
	Player(int initialArmySize);
	Player() = delete;
	~Player();

	void AddSoldier(Soldier* soldier);
	Soldier* GetSoldier(int index);
	int GetArmySize();

private:
	int _armySize = 0;
	std::vector<Soldier*> _soldiers;
};

