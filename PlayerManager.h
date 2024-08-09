#pragma once
#include "Player.h"
#include<vector>

class PlayerManager
{
public:
	PlayerManager(int numberOfPlayers, int defaultNumberOfSoldiers);
	PlayerManager() = delete;
	~PlayerManager();

	void AddNewPlayer();
	void AddNewPlayer(Player* player);
	void AddSoldierForPlayer(int playerIndex, Soldier* soldier);
	int GetPlayerCount();
	int GetSoldierCount();
	Player* GetPlayer(int index);
	
private:
	int _defaultNumberOfSoldiers = 0;
	std::vector<Player*> _players;
};