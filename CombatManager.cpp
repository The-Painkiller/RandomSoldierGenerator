#include "CombatManager.h"

void CombatManager::Initialize(const std::vector<Player*>& playerList, const int playerCount)
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
		if (_currentPlayersList[i]->GetPlayerId() == _currentAttackingPlayerId)
		{
			continue;
		}

		for (int j = 0; j < _currentPlayersList[i]->GetArmySize(); j++)
		{
			_enemySoldiersOnGround.push_back(&_currentPlayersList[i]->GetSoldier(j));
		}
	}
}

void CombatManager::BeginCurrentAttack()
{
	_currentPlayersList[_currentAttackingPlayerId]->ResetIdleSoldierCount();
	for (int i = 0; i < _currentPlayersList[_currentAttackingPlayerId]->GetArmySize(); i++)
	{
		///seek and destroy
		for (int j = 0; j < _enemySoldiersOnGround.size(); j++)
		{
			int attackerPosX = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(i).GetPosition().X;
			int attackerPosY = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(i).GetPosition().Y;
			int enemyPosX = _enemySoldiersOnGround[j]->GetPosition().X;
			int enemyPosY = _enemySoldiersOnGround[j]->GetPosition().Y;

			double attackerRange = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(i).GetAttackRange();

			if (MathUtils::EuclideanDistance(attackerPosX, attackerPosY, enemyPosX, enemyPosY) <= attackerRange)
			{
				///Kill With Power
				int enemyHealth = _enemySoldiersOnGround[j]->GetHealth();
				_currentPlayersList[_currentAttackingPlayerId]->GetSoldier(i).SpecialAttack(enemyHealth);
				_enemySoldiersOnGround[j]->SetHealth(enemyHealth);
				if (enemyHealth == 0)
				{
					_currentPlayersList[_enemySoldiersOnGround[j]->GetParentPlayerId()]->KillSoldier(_enemySoldiersOnGround[j]);
				}
			}
			else
			{
				_currentPlayersList[_currentAttackingPlayerId]->IncrementIdleSoldierCount();
			}
		}
	}
}

CombatManager::~CombatManager()
{
	_currentPlayersList.clear();
	_currentPlayerCount = 0;
	_enemySoldiersOnGround.clear();
}
