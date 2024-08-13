#include "PlayerManager.h"

PlayerManager::PlayerManager(int numberOfPlayers, int defaultNumberOfSoldiers)
{
	_defaultNumberOfSoldiers = defaultNumberOfSoldiers;
	for (int i = 0; i < numberOfPlayers; i++)
	{
		_players.push_back(new Player(_defaultNumberOfSoldiers, i));
	}
}

PlayerManager::~PlayerManager()
{
	for (int i = 0; i < _players.size(); i++)
	{
		delete _players[i];
	}

	_players.clear();
}

void PlayerManager::AddNewPlayer()
{
	_players.push_back(new Player(_defaultNumberOfSoldiers, _players.size()));
}

void PlayerManager::AddNewPlayer(Player* player)
{
	_players.push_back(player);
}

Player* PlayerManager::GetPlayer(int index)
{
	if (_players.empty() || index >= _players.size())
	{
		return NULL;
	}
	return _players[index];
}

void PlayerManager::AddSoldierForPlayer(int playerIndex, Soldier* soldier)
{
	if (_players.empty() || playerIndex >= _players.size())
	{
		return;
	}

	_players[playerIndex]->AddSoldier(soldier);
}

int PlayerManager::GetPlayerCount()
{
	return _players.size();
}

int PlayerManager::GetSoldierCount()
{
	return _defaultNumberOfSoldiers;
}
