#pragma once
#include"Player.h"
#include "MathUtils.h"

class CombatManager
{
public:
	CombatManager() = default;
	~CombatManager();
	
	void Initialize(const std::vector<Player*>& playerList,const int playerCount);

	void SetCurrentTurn(int playerId);
	void BeginCurrentAttack();

private:
	std::vector<Player*> _currentPlayersList;
	int _currentAttackingPlayerId = -1;
	int _currentPlayerCount = 0;
	bool _isBattleOnGoing = false;
	std::vector<Soldier*> _enemySoldiersOnGround;
};

