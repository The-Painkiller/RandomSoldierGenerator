#include "SoldierGreenBeret.h"

void SoldierGreenBeret::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

void SoldierGreenBeret::SpecialAttack(int& enemyHealth)
{
	UniqueAttack(enemyHealth);
}
