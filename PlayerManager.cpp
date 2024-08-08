#include "PlayerManager.h"

PlayerManager::PlayerManager(int numberOfPlayers)
{
	for(int i = 0; i < numberOfPlayers; i++)
	{
		_players.push_back(new Player(_numberOfSoldiers));
	}
}

void PlayerManager::AddNewPlayer()
{
	_players.push_back(new Player(_numberOfSoldiers));
}

void PlayerManager::AddNewPlayer(Player* player)
{
	_players.push_back(player);
}

Player* PlayerManager::GetPlayer(int index)
{
	return _players[index];
}

void PlayerManager::GenerateArmyForPlayer(int playerIndex)
{

}
