#include "UniqueAttackStyle.h"

UniqueAttackStyle::UniqueAttackStyle(int initialDamage)
{
	_damage = initialDamage;
}

int UniqueAttackStyle::GetUniqueDamage()
{
	return _damage;
}

void UniqueAttackStyle::ReduceEnemyHealthWithUniqueAttack(int& enemyHealth)
{
	enemyHealth -= GetUniqueDamage();
	if (enemyHealth < 0)
	{
		enemyHealth = 0;
	}
}