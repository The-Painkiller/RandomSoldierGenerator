#pragma once
#include "Soldier.h"
#include "UniqueAttackAmbushGuerilla.h"

class SoldierSpy : public Soldier, public UniqueAttackAmbushGuerilla
{
public:
	SoldierSpy(int initialHealth, int commonDamage, int initialUniqueDamage) :
		Soldier(Sniper, initialHealth, commonDamage),
		UniqueAttackAmbushGuerilla(initialUniqueDamage) {}

	~SoldierSpy() {}

	void Attack(int& enemHealth) override;
};

