#pragma once
#include "Soldier.h"
#include "UniqueAttackSpecialGuerilla.h"

class SoldierMarine : public Soldier, public UniqueAttackSpecialGuerilla
{
public:
	SoldierMarine(int initialHealth, int commonDamage, int attackRange, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(Marine, initialHealth, commonDamage, attackRange,startPosition),
		UniqueAttackSpecialGuerilla(initialUniqueDamage) {}

	~SoldierMarine() {}

	void Attack(int& enemyHealth) override;
	void SpecialAttack(int& enemyHealth) override;
};

