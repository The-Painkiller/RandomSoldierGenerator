#pragma once
#include "Soldier.h"
#include "UniqueAttackAmbushGuerilla.h"

class SoldierSpy : public Soldier, public UniqueAttackAmbushGuerilla
{
public:
	SoldierSpy(int initialHealth, int commonDamage, int attackRange, int initialUniqueDamage, GridCoordinates startPosition) :
		Soldier(Spy, initialHealth, commonDamage, attackRange, startPosition),
		UniqueAttackAmbushGuerilla(initialUniqueDamage) {}

	~SoldierSpy() {}

	void Attack(int& enemHealth) override;
	void SpecialAttack(int& enemyHealth) override;
};

