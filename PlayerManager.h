#pragma once
#include "Player.h"
#include "SoldierFactory.h"
#include<vector>

class PlayerManager
{
public:
	PlayerManager(int numberOfPlayers);
	PlayerManager() = delete;
	void AddNewPlayer();
	void AddNewPlayer(Player* player);
	Player* GetPlayer(int index);
	void GenerateArmyForPlayer(int playerIndex);
	
private:
	int _numberOfSoldiers = 20;
	std::vector<Player*> _players;
	SoldierFactory *_soldierFactory = new SoldierFactory();
};