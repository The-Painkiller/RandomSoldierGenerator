#pragma once
#include "Player.h"
#include "Event.h"
#include<vector>

class PlayerManager
{
public:
	PlayerManager(int numberOfPlayers, int defaultNumberOfSoldiers);
	PlayerManager() = delete;
	~PlayerManager();

	void AddNewPlayer(Player* player);
	void AddSoldierForPlayer(int playerIndex, Soldier* soldier);
	int GetPlayerCount();
	int GetDefaultNumberOfSoldiers();
	bool AreAllPlayersIdle();
	Player& GetPlayer(int index);
	std::vector<Player*>& GetPlayers();
	
private:
	int _defaultNumberOfSoldiers = 0;
	std::vector<Player*> _players;
};