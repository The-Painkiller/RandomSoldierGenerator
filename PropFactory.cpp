#include "PropFactory.h"

Prop* PropFactory::CreateProp(PropType propType, GridCoordinates position)
{
	switch (propType)
	{
	case HealthBoostType:
		return new PropHealthBoost(MathUtils::Random(50, 100), position);

	case ArmourType:
		return new PropArmour(MathUtils::Random(80, 100), MathUtils::Random(40, 60), MathUtils::Random(10, 30), position);
	case AttackBoostType:
		return new PropAttackBoost(MathUtils::Random(50, 80), position);
	default:
		return nullptr;
	}
}
