#pragma once
#include "Soldier.h"
#include "UniqueAttackSnipe.h"

class SoldierSniper : public Soldier, public UniqueAttackSnipe
{
public:
	SoldierSniper(int initialHealth, int commonDamage, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(Sniper, initialHealth, commonDamage, startPosition),
		UniqueAttackSnipe(initialUniqueDamage) {}

	~SoldierSniper() {}

	void Attack(int& enemyHealth) override;
	void SpecialAttack(int& enemyHealth) override;
};