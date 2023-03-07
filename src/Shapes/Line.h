#ifndef SHAPES_LINE_H_
#define SHAPES_LINE_H_

#include "Vec2D.h"

class Line
{
public:
	Line();
	Line(double x0, double y0, double x1, double y1);
	Line(const Vec2D& p0, const Vec2D& p1);
	virtual ~Line();

	inline const Vec2D& getP0() const { return m_p0; }
	inline const Vec2D& getP1() const { return m_p1; }

	inline void setP0(const Vec2D& p0) { m_p0 = p0; }
	inline void setP1(const Vec2D& p1) { m_p1 = p1; }

	bool operator==(const Line& line) const;
	double shortestDistance(const Vec2D& point, bool limitSegment = false);
	Vec2D closestPoint(const Vec2D& p, bool limitSegment = false);

	Vec2D midpoint() const;
	double slope() const;
	double length() const;

private:
	// Vec2D objects use an x and y
	Vec2D m_p0;
	Vec2D m_p1;
};

#endif /* SHAPES_LINE_H_ */
