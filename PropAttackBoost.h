#pragma once
#include "Prop.h"
class PropAttackBoost : public Prop
{
public:
	PropAttackBoost(int boostAmount, GridCoordinates position) : Prop(AttackBoostType, position)
	{
		_armour = boostAmount;
	}
	PropAttackBoost() = delete;
	~PropAttackBoost() {}

	int GetBoostAmount();
	PropType GetPropType() override;

private:
	int _armour = 0;
};

