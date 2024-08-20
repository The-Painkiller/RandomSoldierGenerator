#include "SoldierMarine.h"

void SoldierMarine::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

int SoldierMarine::GetSpeed()
{
	return Speed;
}
