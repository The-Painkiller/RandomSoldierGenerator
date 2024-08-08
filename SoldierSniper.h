#pragma once
#include "Soldier.h"
#include "UniqueAttackSnipe.h"

class SoldierSniper : public Soldier, public UniqueAttackSnipe
{
public:
	SoldierSniper(int initialHealth, int commonDamage, int initialUniqueDamage) :
		Soldier(Sniper, initialHealth, commonDamage),
		UniqueAttackSnipe(initialUniqueDamage) {}

	~SoldierSniper() {}

	void Attack(int& enemyHealth) override;
};