#include "Soldier.h"

Soldier::Soldier(SoldierType type, int initialHealth, int damage, int attackRange, GridCoordinates position)
{
	_type = type;
	_health = initialHealth;
	_damage = damage;
	_position = position;
	_attackRange = attackRange;
}

void Soldier::SetPlayerId(int Id)
{
	_parentPlayerId = Id;
}

void Soldier::SetHealth(int newHealth)
{
	_health = newHealth;

	if (_health <= 0)
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
	return _health;
}

SoldierType Soldier::GetType()
{
	return _type;
}

int Soldier::GetDamage()
{
	return _damage;
}

int Soldier::GetParentPlayerId()
{
	return _parentPlayerId;
}

double Soldier::GetAttackRange()
{
	return _attackRange;
}

void Soldier::ReduceEnemyHealth(int& enemyHealth)
{
	enemyHealth -= GetDamage();
}