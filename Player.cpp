#include "Player.h"

Player::Player(int initialArmySize)
{
	_armySize = initialArmySize;
}

void Player::AddSoldier(Soldier& soldier)
{
	_soldiers.push_back(&soldier);
}

int Player::GetArmySize()
{
	return _armySize;
}
