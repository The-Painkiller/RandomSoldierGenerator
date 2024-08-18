#include "GameLogger.h"

void GameLogger::LogPlayerArmy(Player& player)
{
	printf("\n");
	printf("\n");
	printf("Player %d:", player.GetPlayerId());
	printf("\n");

	for (int i = 0; i < player.GetArmySize() - 1; i+=2)
	{
		printf("%d:", i);
		printf(GetSoldierTypeName(player.GetSoldier(i).GetType()));
		printf("(%d, %d:%d)",player.GetSoldier(i).GetHealth(), player.GetSoldier(i).GetPosition().X, player.GetSoldier(i).GetPosition().Y);
		printf("\t\t");
		printf("%d:", i+1);
		printf(GetSoldierTypeName(player.GetSoldier(i+1).GetType()));
		printf("(%d, %d:%d)", player.GetSoldier(i+1).GetHealth(), player.GetSoldier(i+1).GetPosition().X, player.GetSoldier(i+1).GetPosition().Y);
		printf("\n");
		printf("\n");
	}
}

void GameLogger::LogAttack(int attackingPlayerId, int attackingSoldierId, int defendingPlayerId, int defendingSoldierId, int defendingSoldierHealth)
{
	printf("P%d S%d -> P%d S%d. Health reduced to %d", attackingPlayerId, attackingSoldierId, defendingPlayerId, defendingSoldierId, defendingSoldierHealth);
	printf("\n");
}

void GameLogger::LogDeath(int dyingSoldierId, int dyingSoldierPlayerId)
{
	printf("P%d S%d dies.", dyingSoldierPlayerId, dyingSoldierId);
	printf("\n");
}

void GameLogger::LogResult(int playerId, bool isVictor)
{
	printf("\n");
	if (isVictor)
	{
		printf("Player %d Won!", playerId);
	}
	else
	{
		printf("Player %d Defeated!", playerId);
	}
}

const char* GameLogger::GetSoldierTypeName(SoldierType type)
{
	switch (type)
	{
	case Sniper:
		return "Sniper";
	case GreenBeret:
		return "Green Beret";
	case Marine:
		return "Marine";
	case Spy:
		return "Spy";
	case None:
		break;
	default:
		return nullptr;
	}
}
