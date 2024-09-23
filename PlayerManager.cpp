#include "PlayerManager.h"

PlayerManager::PlayerManager(int numberOfPlayers, int defaultNumberOfSoldiers)
{
	_defaultNumberOfSoldiers = defaultNumberOfSoldiers;
	for (int i = 0; i < numberOfPlayers; i++)
	{
		PlayerSide side = (PlayerSide)(i + 1);
		_players.push_back(shared_ptr<Player>(new Player(_defaultNumberOfSoldiers, i, side)));
	}
}

PlayerManager::~PlayerManager()
{
	for (int i = 0; i < _players.size(); i++)
	{
		_players[i].reset();
	}

	_players.clear();
}

void PlayerManager::AddNewPlayer(Player* player)
{
	_players.push_back(shared_ptr<Player>(player));
}

Player& PlayerManager::GetPlayer(int index)
{
	if (!_players.empty() && index < _players.size())
	{
		return *_players[index];
	}
}

std::vector<shared_ptr<Player>>& PlayerManager::GetPlayers()
{
	return _players;
}

void PlayerManager::AddSoldierForPlayer(int playerIndex, shared_ptr<Soldier> soldier)
{
	if (_players.empty() || playerIndex >= _players.size())
	{
		return;
	}

	soldier->SetPlayerId(playerIndex);
	_players[playerIndex]->AddSoldier(soldier);
}

int PlayerManager::GetPlayerCount()
{
	return _players.size();
}

int PlayerManager::GetDefaultNumberOfSoldiers()
{
	return _defaultNumberOfSoldiers;
}

bool PlayerManager::AreAllPlayersIdle()
{
	for (int i = 0; i < _players.size(); i++)
	{
		if (_players[i]->GetIdleSoldierCount() < _players[i]->GetArmySize())
		{
			return false;
		}
	}
	
	return true;
}
