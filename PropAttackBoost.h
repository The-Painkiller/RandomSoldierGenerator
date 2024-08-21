#pragma once
#include "Prop.h"
class PropAttackBoost : public Prop
{
public:
	PropAttackBoost(int boost,GridCoordinates position) : Prop(AttackBoostType, position)
	{
		_attackBoost = boost;
	}
	PropAttackBoost() = delete;
	~PropAttackBoost() {}

	int GetBoostAmount();
	PropType GetPropType() override;

private:
	/*
	* Logic:
	* 
	* Permanently increases your attack.
	*/
	int _attackBoost = 0;
};

