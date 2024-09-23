#pragma once
#include "SoldierGreenBeret.h"
#include "SoldierMarine.h"
#include "SoldierSniper.h"
#include "SoldierSpy.h"
#include <memory>

class SoldierFactory
{
public:
	SoldierFactory() = default;
	SoldierFactory(const SoldierFactory&) = delete;

	~SoldierFactory() {}

	std::shared_ptr<Soldier> CreateSoldier(SoldierType soldierType, GridCoordinates startPosition);

private:
	int BaseCommonDamage = 30;
};