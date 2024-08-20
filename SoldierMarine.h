#pragma once
#include "Soldier.h"

class SoldierMarine : public Soldier
{
public:
	SoldierMarine(int initialHealth, int damage, int attackRange, GridCoordinates startPosition) :
		Soldier(Marine, initialHealth, damage, attackRange, startPosition) {}

	~SoldierMarine() {}

	void Attack(int& enemyHealth) override;
	int GetSpeed() override;

private:
	const int Speed = 6;
};