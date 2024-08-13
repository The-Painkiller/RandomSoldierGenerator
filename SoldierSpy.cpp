#include "SoldierSpy.h"

void SoldierSpy::Attack(int& enemHealth)
{
	ReduceEnemyHealth(enemHealth);
}

void SoldierSpy::SpecialAttack(int& enemyHealth)
{
	UniqueAttack(enemyHealth);
}
