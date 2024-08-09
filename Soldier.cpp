#include "Soldier.h"

Soldier::Soldier(SoldierType type, int initialHealth, int commonDamage, GridCoordinates position)
{
	_type = type;
	_health = initialHealth;
	_commonDamage = commonDamage;
	_position = position;
}

void Soldier::SetDamage(int damage)
{
	_health -= damage;

	if (_health < 0)
	{
		_health = 0;
	}
}

void Soldier::SetPosition(GridCoordinates position)
{
	_position = position;
}

GridCoordinates Soldier::GetPosition()
{
	return _position;
}

int Soldier::GetHealth()
{
	return 0;
}

SoldierType Soldier::GetType()
{
	return _type;
}

int Soldier::GetCommonDamage()
{
	return _commonDamage;
}

void Soldier::ReduceEnemyHealth(int& enemyHealth)
{
	enemyHealth -= GetCommonDamage();
	if (enemyHealth < 0)
	{
		enemyHealth = 0;
	}
}