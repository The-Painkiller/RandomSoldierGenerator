#pragma once
#include"Player.h"
#include "MathUtils.h"
#include"GameLogger.h"
#include "Event.h"

class CombatManager : public Event
{
public:
	CombatManager() = default;
	~CombatManager();
	
	void Initialize(const std::vector<Player*>& playerList,const int playerCount);

	void SetCurrentTurn(int playerId);
	void BeginCurrentAttack();
	void CheckArmyStatus();

private:
	int _currentAttackingPlayerId = -1;
	int _currentPlayerCount = 0;
	bool _isBattleOnGoing = false;
	std::vector<Player*> _currentPlayersList;
	std::vector<Soldier*> _enemySoldiersOnGround;
	bool SeekAndDestroy(int attackingSoldierId);
};