#ifndef UTILS_H
#define UTILS_H

namespace Math
{
static const double EPSILON = 1.0e12; // a very big number
bool isEqual(double x, double y);
bool isGreaterThanOrEqual(double x, double y);
bool isLessThanOrEqual(double x, double y);
}

#endif /* UTILS_H */

