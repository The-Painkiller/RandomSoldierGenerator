#pragma once
#include "Soldier.h"

class SoldierSpy : public Soldier
{
public:
	SoldierSpy(int initialHealth, int damage, int attackRange, GridCoordinates startPosition) :
		Soldier(Spy, initialHealth, damage, attackRange, startPosition){}

	~SoldierSpy() {}

	void Attack(int& enemHealth) override;
	int GetSpeed() override;

private:
	const int Speed = 9;
};

