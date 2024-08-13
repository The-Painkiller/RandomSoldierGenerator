#include "Player.h"

Player::Player(int initialArmySize, int playerId)
{
	_armySize = initialArmySize;
	_playerId = playerId;
}

Player::~Player()
{
	for (int i = 0; i < _soldiers.size(); i++)
	{
		delete _soldiers[i];
	}

	_soldiers.clear();
}

void Player::AddSoldier(Soldier* soldier)
{
	_soldiers.push_back(soldier);
}

Soldier* Player::GetSoldier(int index)
{
	return _soldiers[index];
}

int Player::GetArmySize()
{
	return _armySize;
}

int Player::GetPlayerId()
{
	return _playerId;
}
