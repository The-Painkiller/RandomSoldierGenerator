#pragma once
#include "Prop.h"
class PropArmour : public Prop
{
public:
	PropArmour(int armourAmount, int healthAffectThresholdPercent, int healthDamagePercentage, GridCoordinates position) : Prop(ArmourType, position)
	{
		_armour = armourAmount;
		_healthAffectThresholdPercentage = healthAffectThresholdPercent;
		_healthDamagePercentage = healthDamagePercentage;
	}
	PropArmour() = delete;
	~PropArmour() {}

	int GetArmourAmount();
	int GetHealthAffectThreshold();
	int GetHealthDamage();
	void SetArmourAmount(const int armour);
	PropType GetPropType() override;

private:
	/*
	* Logic:
	* If armour = 100, health = 100, healthAffectThreshold = 30%, healthProtection = 20%
	* Then if you get hit by Damage 20, armour = 80 but health not affected.
	* If you get hit by Damage 30, armour = 50, health -= 80 x 20%, i.e. health -= 16, i.e., health = 84.
	* If you get hit by Damage 80, armour = 0, health -= 50 x 20%, i.e. health -= 10, i.e., health = 74.
	* If you get hit by Damage 80 now, health = 0. You die.
	*/
	int _armour = 0;
	int _healthAffectThresholdPercentage = 30;
	int _healthDamagePercentage = 20;
};

