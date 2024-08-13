#include "MathUtils.h"

double MathUtils::EuclideanDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}
