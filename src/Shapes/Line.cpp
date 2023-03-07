#include <cmath>
#include <algorithm>
#include "Line.h"
#include "Utils.h"

// Default constructor
Line::Line() : m_p0(0, 0), m_p1(0, 0)
{
}

// Constructor with values passed in for points
Line::Line(double x0, double y0, double x1, double y1)
: m_p0(x0, y0), m_p1(x1, y1)
{
}

// Constructor with Vec2D objects passed in for points
Line::Line(const Vec2D& p0, const Vec2D& p1)
: m_p0(p0), m_p1(p1)
{

}

Line::~Line()
{
}

bool Line::operator==(const Line& line) const
{
	return  line.getP0() == m_p0 && line.getP1() == m_p1;
}

double Line::shortestDistance(const Vec2D& p, bool limitSegment)
{
	return p.distance(closestPoint(p, limitSegment));
}

Vec2D Line::closestPoint(const Vec2D& point, bool limitSegment)
{
	// Calculate vectors from p0 to point and from p0 to p1
	Vec2D pointToP0 = point - m_p0;
	Vec2D p0ToP1 = m_p1 - m_p0;

	// Calculate the square of the length from p0 to p1
	double p0ToP1Sqr = p0ToP1.squares();

	// Calculate dot product from p0 to point and p0 to p1
	double dot = pointToP0.dot(p0ToP1);

	// Calculate the position of the closest point
	double paramT = dot / p0ToP1Sqr;

	if (limitSegment)
	{
		// clamp the position to 0 to 1
		paramT = std::clamp(paramT, 0.0, 1.0);
	}

	// return the closest point to the line
	return m_p0 + p0ToP1 * paramT;
}

/*
 * Midpoint formula
 *
 * (xm, ym) = ((x0 + x2) / 2, (y0, y1) / 2)
 */

Vec2D Line::midpoint() const
{
	return Vec2D((m_p0.getX() + m_p1.getX()) / 2.0, (m_p0.getY() + m_p1.getY()) / 2.0);
}

/*
 * Slope formula
 *
 * slope = rise / run = y1 - y0 / x1 - x0
 */

double Line::slope() const
{
	double run = m_p1.getX() - m_p0.getX();
	if (std::abs(run) < Math::EPSILON)
	{
		return 0;
	}
	double rise = m_p1.getY() - m_p0.getY();
	return rise / run;
}

/*
 * Distance of a line formula
 *
 * sqrt((x1 - x0)^2 + (y1 - y0)^2) \ already defined in Vec2D
 */

double Line::length() const
{
	return m_p1.distance(m_p0);
}

