#include "SoldierFactory.h"

Soldier* SoldierFactory::CreateSoldier(SoldierType soldierType)
{
    switch(soldierType)
    {
    case GreenBeret:
        return new SoldierGreenBeret(100, BaseCommonDamage, 80);

    case Marine:
        return new SoldierMarine(80, BaseCommonDamage, 60);

    case Sniper:
        return new SoldierSniper(50, BaseCommonDamage, 100);

    case Spy:
        return new SoldierSpy(60, BaseCommonDamage, 70);

    default:
        return nullptr;
    }
}
