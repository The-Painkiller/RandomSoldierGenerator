#pragma once
#include "Soldier.h"
#include "UniqueAttackAmbushGuerilla.h"

class SoldierSpy : public Soldier, public UniqueAttackAmbushGuerilla
{
public:
	SoldierSpy(int initialHealth, int commonDamage, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(Spy, initialHealth, commonDamage, startPosition),
		UniqueAttackAmbushGuerilla(initialUniqueDamage) {}

	~SoldierSpy() {}

	void Attack(int& enemHealth) override;
};

