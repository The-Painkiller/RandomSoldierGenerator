#pragma once
#include "Player.h"
#include "Event.h"
#include<vector>
#include<memory>
using namespace std;

class PlayerManager
{
public:
	PlayerManager(int numberOfPlayers, int defaultNumberOfSoldiers);
	PlayerManager() = delete;
	~PlayerManager();

	void AddNewPlayer(Player* player);
	void AddSoldierForPlayer(int playerIndex, shared_ptr<Soldier> soldier);
	int GetPlayerCount();
	int GetDefaultNumberOfSoldiers();
	bool AreAllPlayersIdle();
	Player& GetPlayer(int index);
	std::vector<shared_ptr<Player>>& GetPlayers();
	
private:
	int _defaultNumberOfSoldiers = 0;
	std::vector<shared_ptr<Player>> _players;
};