#include "SoldierFactory.h"

std::shared_ptr<Soldier> SoldierFactory::CreateSoldier(SoldierType soldierType, GridCoordinates startPosition)
{
    switch(soldierType)
    {
    case GreenBeret:
        return std::shared_ptr<SoldierGreenBeret>(new SoldierGreenBeret(100, 80, 30, startPosition));

    case Marine:
        return std::shared_ptr<SoldierMarine>(new SoldierMarine(80, 60, 50, startPosition));

    case Sniper:
        return std::shared_ptr<SoldierSniper>(new SoldierSniper(50, 100, 150, startPosition));

    case Spy:
        return std::shared_ptr<SoldierSpy>(new SoldierSpy(60, 70, 20, startPosition));

    default:
        return nullptr;
    }
}
