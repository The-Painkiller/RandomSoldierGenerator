#pragma once
#include "Soldier.h"
#include "UniqueAttackSpecialGuerilla.h"

class SoldierMarine : public Soldier, public UniqueAttackSpecialGuerilla
{
public:
	SoldierMarine(int initialHealth, int commonDamage, int initialUniqueDamage) :
		Soldier(Sniper, initialHealth, commonDamage),
		UniqueAttackSpecialGuerilla(initialUniqueDamage) {}

	~SoldierMarine() {}

	void Attack(int& enemyHealth) override;
};

