#pragma once

#include "Soldier.h"

class SoldierGreenBeret : public Soldier
{
public:
	SoldierGreenBeret(int initialHealth, int damage, int attackRange, GridCoordinates startPosition) :
		Soldier(GreenBeret, initialHealth, damage, attackRange, startPosition) {}

	~SoldierGreenBeret(){}

	void Attack(int& enemyHealth) override;
	int GetSpeed() override;

private:
	const int Speed = 7;
};