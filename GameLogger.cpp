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
		printf("\t\t");
		printf("%d:", i+1);
		printf(GetSoldierTypeName(player.GetSoldier(i+1).GetType()));
		printf("\n");
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
