#pragma once
#include "PropArmour.h"
#include "PropAttackBoost.h"
#include "PropHealthBoost.h"
#include "MathUtils.h"

class PropFactory
{
public:
	PropFactory() = default;
	PropFactory(const PropFactory&) = delete;
	~PropFactory() = default;

	Prop* CreateProp(PropType propType, GridCoordinates position);
};

