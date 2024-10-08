#pragma once
#include "Soldier.h"

class SoldierSniper : public Soldier
{
public:
	SoldierSniper(int initialHealth, int damage, int attackRange, GridCoordinates startPosition) :
		Soldier(Sniper, initialHealth, damage, attackRange, startPosition)
	{
		_defaultHealth = initialHealth;
	}

	~SoldierSniper() {}

	void Attack(int& enemyHealth) override;
	int GetSpeed() override;

private:
	const int Speed = 8;
};