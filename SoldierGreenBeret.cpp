#include "SoldierGreenBeret.h"

void SoldierGreenBeret::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

int SoldierGreenBeret::GetSpeed()
{
	return Speed;
}
