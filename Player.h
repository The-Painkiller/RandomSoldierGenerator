#pragma once
#include "Soldier.h"
#include<vector>
class Player
{
public:
	Player(int initialArmySize);
	Player() = delete;

	void AddSoldier(Soldier& soldier);
	int GetArmySize();

private:
	int _armySize = 0;
	std::vector<Soldier*> _soldiers;
};

