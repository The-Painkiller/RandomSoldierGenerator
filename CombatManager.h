#pragma once
#include"Player.h"
#include "MathUtils.h"

class CombatManager
{
public:
	CombatManager() = default;
	~CombatManager();
	
	void Initialize(Player* playerList,const int playerCount);

	void SetCurrentTurn(int playerId);
	void BeginCurrentAttack();

private:
	Player* _currentPlayersList = nullptr;
	int _currentAttackingPlayerId = -1;
	int _currentPlayerCount = 0;
	bool _isBattleOnGoing = false;
	std::vector<Soldier&> _enemySoldiersOnGround;
};

