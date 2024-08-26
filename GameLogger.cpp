#include "GameLogger.h"

void GameLogger::LogPlayerArmy(Player& player)
{
	printf("\n");
	printf("Player %d:", player.GetPlayerId());
	printf("\n");

	for (int i = 0; i < player.GetArmySize(); i++)
	{
		printf("%d:", i);
		printf(GetSoldierTypeName(player.GetSoldier(i).GetType()));
		printf("(%d, %d:%d)",player.GetSoldier(i).GetHealth(), player.GetSoldier(i).GetPosition().X, player.GetSoldier(i).GetPosition().Y);
		printf("\n");
	}
}

void GameLogger::LogAttack(int attackingPlayerId, int attackingSoldierId, int defendingPlayerId, int defendingSoldierId, int defendingSoldierHealth)
{
	printf("\n");
	printf("P%d S%d -> P%d S%d. Health reduced to %d. ", attackingPlayerId, attackingSoldierId, defendingPlayerId, defendingSoldierId, defendingSoldierHealth);
	if (defendingSoldierHealth <= 0)
	{
		printf("P%d S%d Dies!", defendingPlayerId, defendingSoldierId);
	}
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

void GameLogger::LogText(const char* text)
{
	printf("\n");
	printf(text);
	printf("\n");
}

void GameLogger::LogPropConsumption(int playerId, int soldierId, Prop* prop)
{
	printf("\n");
	printf("P%d S%d grabs ", playerId, soldierId);
	printf(GetPropTypeName(prop->GetPropType()));
	
	switch (prop->GetPropType())
	{
	case HealthBoostType:
		printf(" BoostAmt: %d",(dynamic_cast<PropHealthBoost*>(prop))->GetBoostAmount());
		break;
	case ArmourType:
		printf(" ArmourAmt: %d", (dynamic_cast<PropArmour*>(prop))->GetArmourAmount());
		break;
	case AttackBoostType:
		printf(" BoostAmt: %d", (dynamic_cast<PropAttackBoost*>(prop))->GetBoostAmount());
		break;
	default:
		break;
	}

	printf("\n");
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
	default:
		return nullptr;
	}
}

const char* GameLogger::GetPropTypeName(PropType type)
{
	switch (type)
	{
	case DudProp:
		return "Dud";
	case HealthBoostType:
		return "HealthBoost";
	case ArmourType:
		return "Armour";
	case AttackBoostType:
		return "AttackBoost";
	default:
		break;
	}
	return nullptr;
}
