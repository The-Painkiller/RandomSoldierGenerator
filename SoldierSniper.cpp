#include "SoldierSniper.h"

void SoldierSniper::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

int SoldierSniper::GetSpeed()
{
	return Speed;
}
