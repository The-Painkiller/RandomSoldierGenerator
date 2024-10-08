#pragma once
#include"Player.h"
#include "MathUtils.h"
#include"GameLogger.h"
#include "Event.h"
#include<memory>
using namespace std;

class CombatManager
{
public:
	CombatManager() = default;
	~CombatManager();
	
	void Initialize(const std::vector<shared_ptr<Player>>& playerList,const int playerCount);

	void SetCurrentTurn(int playerId);
	void BeginCurrentAttack();
	void CheckArmyStatus();
	void RegisterEventHandler(EventHandler& handler);
	int GetCurrentAttackingPlayerId();

private:
	int _currentAttackingPlayerId = -1;
	int _currentPlayerCount = 0;
	bool _isBattleOnGoing = false;
	std::vector<shared_ptr<Player>> _currentPlayersList;
	std::vector<shared_ptr<Soldier>> _enemySoldiersOnGround;
	bool SeekAndDestroy(int attackingSoldierId);
	unique_ptr<Event> _event = unique_ptr<Event>(new Event());
};