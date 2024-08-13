#include "SoldierSniper.h"

void SoldierSniper::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

void SoldierSniper::SpecialAttack(int& enemyHealth)
{
	UniqueAttack(enemyHealth);
}
