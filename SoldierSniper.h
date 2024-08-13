#pragma once
#include "Soldier.h"
#include "UniqueAttackSnipe.h"

class SoldierSniper : public Soldier, public UniqueAttackSnipe
{
public:
	SoldierSniper(int initialHealth, int commonDamage, int attackRange, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(Sniper, initialHealth, commonDamage, attackRange, startPosition),
		UniqueAttackSnipe(initialUniqueDamage) {}

	~SoldierSniper() {}

	void Attack(int& enemyHealth) override;
	void SpecialAttack(int& enemyHealth) override;
};