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
	case 1:
		newPos = currentPosOnMoveAxis + speed;
		if (newPos >= boundaryPosOnMoveAxis)
		{
			newPos = boundaryPosOnMoveAxis;
		}
		break;
	case 2:
		newPos = currentPosOnMoveAxis - speed;
		if (newPos <= boundaryPosOnMoveAxis)
		{
			newPos = boundaryPosOnMoveAxis;
		}
		break;
	default:
		return 0;
	};

	return newPos;
}
