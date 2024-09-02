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
		if (!SeekAndDestroy(i))
		{
			//increment idle count
			_currentPlayersList[_currentAttackingPlayerId]->IncrementIdleSoldierCount();
		}
	}
	CheckArmyStatus();
}

bool CombatManager::SeekAndDestroy(int attackingSoldierId)
{
	for (int i = 0; i < _enemySoldiersOnGround.size(); i++)
	{
		int attackerPosX = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(attackingSoldierId).GetPosition().X;
		int attackerPosY = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(attackingSoldierId).GetPosition().Y;
		int enemyPosX = _enemySoldiersOnGround[i]->GetPosition().X;
		int enemyPosY = _enemySoldiersOnGround[i]->GetPosition().Y;

		double attackerRange = _currentPlayersList[_currentAttackingPlayerId]->GetSoldier(attackingSoldierId).GetAttackRange();

		if (MathUtils::EuclideanDistance(attackerPosX, attackerPosY, enemyPosX, enemyPosY) <= attackerRange)
		{
			///Kill With Power
			int enemyHealth = _enemySoldiersOnGround[i]->GetHealth();
			_currentPlayersList[_currentAttackingPlayerId]->GetSoldier(attackingSoldierId).Attack(enemyHealth);
			_enemySoldiersOnGround[i]->SetHealth(enemyHealth, true);

			GameLogger::LogAttack(_currentAttackingPlayerId, attackingSoldierId, _enemySoldiersOnGround[i]->GetParentPlayerId(), i, _enemySoldiersOnGround[i]->GetHealth());

			_event->Invoke(SoldierHurt, {enemyPosX, enemyPosY}, _enemySoldiersOnGround[i]->GetParentPlayerId());

			if (enemyHealth <= 0)
			{
				_currentPlayersList[_enemySoldiersOnGround[i]->GetParentPlayerId()]->KillSoldier(_enemySoldiersOnGround[i]);
				_enemySoldiersOnGround.erase(_enemySoldiersOnGround.begin() + i);
				_event->Invoke(SoldierDeath, enemyPosX, enemyPosY);
			}
			std::this_thread::sleep_for(std::chrono::milliseconds(ThreadSleepTime));
			return true;
		}
	}
	return false;
}

void CombatManager::CheckArmyStatus()
{
	for (int i = 0; i < _currentPlayersList.size(); i++)
	{
		 if (_currentPlayersList[i]->GetArmySize() <= 0)
		{
			 _currentPlayersList[i]->SetDefeated();
			 _event->Invoke(GameOver, i, -1);
			GameLogger::LogResult(_currentPlayersList[i]->GetPlayerId() + 1, false);
			break;
		}
	}
}

void CombatManager::RegisterEventHandler(EventHandler* handler)
{
	_event->Register(handler);
}

int CombatManager::GetCurrentAttackingPlayerId()
{
	return _currentAttackingPlayerId;
}

CombatManager::~CombatManager()
{
	_currentPlayersList.clear();
	_currentPlayerCount = 0;
	_currentAttackingPlayerId = -1;
	_isBattleOnGoing = false;
	_enemySoldiersOnGround.clear();
}
