#pragma once
#include "GlobalEnums.h"
class Object
{
public:
	virtual void SetPosition(GridCoordinates position) = 0;
	virtual GridCoordinates GetPosition() = 0;

protected:
	GridCoordinates _position;
};

