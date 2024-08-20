#include "Player.h"

Player::Player(int initialArmySize, int playerId, PlayerSide playerSide)
{
	_armySize = initialArmySize;
	_playerId = playerId;
	_playerSide = playerSide;
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

Soldier& Player::GetSoldier(int index)
{
	return *_soldiers[index];
}

int Player::GetArmySize()
{
	return _soldiers.size();
}

int Player::GetPlayerId()
{
	return _playerId;
}

int Player::GetIdleSoldierCount()
{
	return _idleSoldierCounter;
}

PlayerSide Player::GetPlayerSide()
{
	return _playerSide;
}

void Player::KillSoldier(Soldier* dyingSoldier)
{
	auto iter = std::find(_soldiers.begin(), _soldiers.end(), dyingSoldier);
	if (iter != _soldiers.end())
	{
		_soldiers.erase(iter);
	}

	delete dyingSoldier;
}

void Player::IncrementIdleSoldierCount()
{
	_idleSoldierCounter += 1;
}

void Player::ResetIdleSoldierCount()
{
	_idleSoldierCounter = 0;
}

void Player::MoveArmy(GridCoordinates boundary)
{
	GridCoordinates pos;
	for (int i = 0; i < _soldiers.size(); i++)
	{
		pos = _soldiers[i]->GetPosition();
		pos.X = MathUtils::NewPosition(_playerSide, pos.X, boundary.X, _soldiers[i]->GetSpeed());
		_soldiers[i]->SetPosition(pos);
	}
}