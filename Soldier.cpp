#include "Soldier.h"

Soldier::Soldier(SoldierType type, int initialHealth, int damage, int attackRange, GridCoordinates position)
{
	_type = type;
	_health = initialHealth;
	_damage = damage;
	_position = position;
	_attackRange = attackRange;
}

Soldier::~Soldier()
{
	delete _armour;
	_armour = nullptr;
}

void Soldier::SetPlayerId(int Id)
{
	_parentPlayerId = Id;
}

void Soldier::SetHealth(int newHealth, bool isDamage)
{
	if (_armour != nullptr && _armour->GetArmourAmount() >= 0 && isDamage)
	{
		int armourAmount = _armour->GetArmourAmount();
		int healthAffectThreshold = _armour->GetHealthAffectThreshold();
		int healthDamagePercent = _armour->GetHealthDamage();
		int damageTaken = _health - newHealth;

		armourAmount -= damageTaken;
		if (armourAmount <= 0)
		{
			RemoveArmour();
		}
		else
		{
			_armour->SetArmourAmount(armourAmount);
		}

		if (damageTaken < healthAffectThreshold)
		{
			return;
		}
		else
		{
			damageTaken *= healthAffectThreshold / 100.0f;
			_health -= damageTaken;
		}
	}
	else
	{
		_health = newHealth;
	}

	

	if (_health <= 0)
	{
		_health = 0;
	}
}

void Soldier::SetArmour(PropArmour* armour)
{
	_armour = new PropArmour(*armour);
}

void Soldier::SetDamage(int damage)
{
	_damage = damage;
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

void Soldier::RemoveArmour()
{
	delete _armour;
	_armour = nullptr;
}
