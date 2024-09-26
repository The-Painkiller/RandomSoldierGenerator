#include "Player.h"

std::unique_ptr<Event> Player::PlayerEvent = std::unique_ptr<Event>(new Event());

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
		_soldiers[i].reset();
	}

	_soldiers.clear();
	PlayerEvent = nullptr;
}

void Player::AddSoldier(std::shared_ptr<Soldier> soldier)
{
	_soldiers.push_back(soldier);
}

std::shared_ptr<Soldier> Player::GetSoldier(int index)
{
	return _soldiers[index];
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

void Player::KillSoldier(std::shared_ptr<Soldier> dyingSoldier)
{
	auto iter = std::find(_soldiers.begin(), _soldiers.end(), dyingSoldier);
	if (iter != _soldiers.end())
	{
		_soldiers.erase(iter);
	}

	dyingSoldier.reset();
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

		PlayerEvent->Invoke(SoldierMove, pos, _soldiers[i]->GetParentPlayerId());

		std::this_thread::sleep_for(std::chrono::milliseconds(ThreadSleepTime));
	}
}

void Player::SetDefeated()
{
	_isPlayerDefeated = true;
}

void Player::RegisterEventHandler(EventHandler& handler)
{
	PlayerEvent->Register(&handler);
}

bool Player::IsDefeated()
{
	return _isPlayerDefeated;
}
