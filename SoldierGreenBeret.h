#pragma once
#include "Soldier.h";
#include "UniqueAttackGuerilla.h"

class SoldierGreenBeret : public Soldier, public UniqueAttackGuerilla
{
public:
	SoldierGreenBeret(int initialHealth, int commonDamage, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(GreenBeret, initialHealth, commonDamage, startPosition),
		UniqueAttackGuerilla(initialUniqueDamage) {}

	~SoldierGreenBeret(){}

	void Attack(int& enemyHealth) override;
};

