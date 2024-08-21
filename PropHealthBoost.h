#pragma once
#include "Prop.h"
class PropHealthBoost : public Prop
{
public:
	PropHealthBoost(int boostAmount, GridCoordinates position) : Prop(HealthBoostType, position)
	{
		_boost = boostAmount;
	}
	PropHealthBoost() = delete;
	~PropHealthBoost() {}

	int GetBoostAmount();
	PropType GetPropType() override;

private:
	/*
	* Logic:
	* 
	* Permanently increases your health.
	*/
	int _boost = 0;
};