#include "MathUtils.h"

double MathUtils::EuclideanDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}

int MathUtils::NewPosition(int direction, int currentPosOnMoveAxis, int boundaryPosOnMoveAxis , int speed)
{
	int newPos = 0;
	switch (direction)
	{
	case 1://Left
		newPos = currentPosOnMoveAxis + speed;
		if (newPos >= boundaryPosOnMoveAxis)
		{
			newPos = boundaryPosOnMoveAxis - 1;
		}
		break;
	case 2://Right
		newPos = currentPosOnMoveAxis - speed;
		if (newPos < 0)
		{
			newPos = 0;
		}
		break;
	default:
		return 0;
	};

	return newPos;
}

int MathUtils::Random(int floor, int ceilingNotIncluded)
{
	return rand() % (ceilingNotIncluded - floor) + floor;
}
