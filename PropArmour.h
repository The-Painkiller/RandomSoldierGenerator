#pragma once
#include "Prop.h"
class PropArmour : public Prop
{
public:
	PropArmour(int armourAmount, GridCoordinates position) : Prop(ArmourType, position)
	{
		_armour = armourAmount;
	}
	PropArmour() = delete;
	~PropArmour() {}

	int GetArmourAmount();
	PropType GetPropType() override;

private:
	int _armour = 0;
};

