#include "CombatManager.h"

void CombatManager::Initialize(Player* playerList, const int playerCount)
{
	_currentPlayersList = playerList;
	_currentPlayerCount = playerCount;
}

void CombatManager::SetCurrentTurn(int playerId)
{
	_currentAttackingPlayerId = playerId;
	_enemySoldiersOnGround.clear();

	for (int i = 0; i < _currentPlayerCount; i++)
	{
		if (_currentPlayersList[i].GetPlayerId() == _currentAttackingPlayerId)
		{
			continue;
		}

		for (int j = 0; j < _currentPlayersList[i].GetArmySize(); i++)
		{
			_enemySoldiersOnGround.push_back(*_currentPlayersList[i].GetSoldier(j));
		}
	}
}

void CombatManager::BeginCurrentAttack()
{
	for (int i = 0; i < _currentPlayersList[_currentAttackingPlayerId].GetArmySize(); i++)
	{
		///seek and destroy
		for (int j = 0; j < _enemySoldiersOnGround.size(); j++)
		{
			int attackerPosX = _currentPlayersList[_currentAttackingPlayerId].GetSoldier(i)->GetPosition().X;
			int attackerPosY = _currentPlayersList[_currentAttackingPlayerId].GetSoldier(i)->GetPosition().Y;
			int enemyPosX = _enemySoldiersOnGround[j].GetPosition().X;
			int enemyPosY = _enemySoldiersOnGround[j].GetPosition().Y;

			int attackerRange = _currentPlayersList[_currentAttackingPlayerId].GetSoldier(i)->GetAttackRange();

			if (MathUtils::EuclideanDistance(attackerPosX, attackerPosY, enemyPosX, enemyPosY) <= attackerRange)
			{
				///Kill With Power
			}
		}
	}
}

//void CombatManager::BeginBattle()
//{
//	if (_currentPlayersList == nullptr || _currentPlayerCount == 0)
//	{
//		return;
//	}
//
//	_isBattleOnGoing = true;
//	while (_isBattleOnGoing)
//	{
//		for (int playerIndex = 0; playerIndex < _currentPlayerCount; playerIndex++)
//		{
//			_currentAttackingPlayerId = _currentDefendingPlayerIds.at(0);
//			_currentDefendingPlayerIds.erase(_currentDefendingPlayerIds.begin());
//			
//			
//			for (int soldierIndex = 0; soldierIndex < _currentPlayersList[playerIndex].GetArmySize(); soldierIndex++)
//			{
//				for(int i = 0; i < _soldiersOnGround.size())
//			}
//
//
//			_currentDefendingPlayerIds.push_back(_currentAttackingPlayerId);
//		}
//	}
//}

CombatManager::~CombatManager()
{
	delete _currentPlayersList;
	_currentPlayersList = nullptr;
	_currentPlayerCount = 0;
}
