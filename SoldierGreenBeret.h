#pragma once
#include "Soldier.h";
#include "UniqueAttackGuerilla.h"

class SoldierGreenBeret : public Soldier, public UniqueAttackGuerilla
{
public:
	SoldierGreenBeret(int initialHealth, int commonDamage, int initialUniqueDamage) :
		Soldier(GreenBeret, initialHealth, commonDamage),
		UniqueAttackGuerilla(initialUniqueDamage) {}

	~SoldierGreenBeret(){}

	void Attack(int& enemyHealth) override;
};

