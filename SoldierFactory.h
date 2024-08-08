#pragma once
#include "SoldierGreenBeret.h"
#include "SoldierMarine.h"
#include "SoldierSniper.h"
#include "SoldierSpy.h"

class SoldierFactory
{
public:
	SoldierFactory() = default;
	SoldierFactory(const SoldierFactory&) = delete;

	~SoldierFactory() {}

	Soldier* CreateSoldier(SoldierType soldierType);

private:
	int BaseCommonDamage = 30;
};

