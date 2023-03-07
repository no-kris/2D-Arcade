#include <cmath>

#include "Utils.h"

namespace Math
{

bool isEqual(double x, double y)
{
	return std::abs(x - y) < EPSILON;
}

bool isGreaterThanOrEqual(double x, double y)
{
	return x > y || isEqual(x, y);
}

bool isLessThanOrEqual(double x, double y)
{
	return x < y || isEqual(x, y);
}

}

