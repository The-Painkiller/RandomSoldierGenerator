#include "SoldierMarine.h"

void SoldierMarine::Attack(int& enemyHealth)
{
	ReduceEnemyHealth(enemyHealth);
}

void SoldierMarine::SpecialAttack(int& enemyHealth)
{
	UniqueAttack(enemyHealth);
}
