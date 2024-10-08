#pragma once
#include<cmath>
class MathUtils
{
public:
	MathUtils() = delete;
	MathUtils(const MathUtils&) = delete;
	~MathUtils() {}

	static double EuclideanDistance(int x1, int y1, int x2, int y2);
	static int NewPosition(int direction, int currentPosOnMoveAxis, int boundaryPosOnMoveAxis, int speed);
	static int Random(int floor, int ceilingNotIncluded);
};

