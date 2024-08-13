#pragma once
#include<cmath>
class MathUtils
{
public:
	MathUtils() = delete;
	MathUtils(const MathUtils&) = delete;
	~MathUtils() {}

	static double EuclideanDistance(int x1, int y1, int x2, int y2);
};

