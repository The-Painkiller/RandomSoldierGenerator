#include "SoldierFactory.h"

Soldier* SoldierFactory::CreateSoldier(SoldierType soldierType, GridCoordinates startPosition)
{
    switch(soldierType)
    {
    case GreenBeret:
        return new SoldierGreenBeret(100, BaseCommonDamage, 80, startPosition);

    case Marine:
        return new SoldierMarine(80, BaseCommonDamage, 60, startPosition);

    case Sniper:
        return new SoldierSniper(50, BaseCommonDamage, 100, startPosition);

    case Spy:
        return new SoldierSpy(60, BaseCommonDamage, 70, startPosition);

    default:
        return nullptr;
    }
}
