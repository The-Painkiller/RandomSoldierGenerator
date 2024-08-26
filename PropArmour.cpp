#include "PropArmour.h"

int PropArmour::GetArmourAmount()
{
    return _armour;
}

int PropArmour::GetHealthAffectThreshold()
{
    return _healthAffectThresholdPercentage;
}

int PropArmour::GetHealthDamage()
{
    return _healthDamagePercentage;
}

void PropArmour::SetArmourAmount(const int armour)
{
    _armour = armour;

    if (_armour < 0)
    {
        _armour = 0;
    }
}

PropType PropArmour::GetPropType()
{
    return _type;
}
