#include "SoldierFactory.h"

Soldier* SoldierFactory::CreateSoldier(SoldierType soldierType, GridCoordinates startPosition)
{
    switch(soldierType)
    {
    case GreenBeret:
        return new SoldierGreenBeret(100, 80, 30, startPosition);

    case Marine:
        return new SoldierMarine(80, 60, 50, startPosition);

    case Sniper:
        return new SoldierSniper(50, 100, 150, startPosition);

    case Spy:
        return new SoldierSpy(60, 70, 20, startPosition);

    default:
        return nullptr;
    }
}
