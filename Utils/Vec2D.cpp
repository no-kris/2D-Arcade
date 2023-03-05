#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <cmath>
#include <complex>
#include "Vec2D.h"
#include "Utils.h"

// Default constructor calls parameterized constructor

Vec2D::Vec2D()
: Vec2D(0, 0)
{
}

Vec2D::Vec2D(double x, double y)
: m_X(x), m_Y(y)
{
}

Vec2D::~Vec2D()
{
}

/*
 * Overloading equality operators 
 * 
 * Compare the member variables, x and y, of 
 * this vec object with another vec object 
 */

bool Vec2D::operator==(const Vec2D& otherVec) const
{
    return Math::isEqual(m_X, otherVec.m_X) && Math::isEqual(m_Y, otherVec.m_Y);
}

bool Vec2D::operator!=(const Vec2D& otherVec) const
{
    return !(*this == otherVec); // This calls the operator== function
}

/*
 * Overloading operator-, non-parameterized
 * 
 * Return a new vec object with negative x and y
 */

Vec2D Vec2D::operator-() const
{
    return Vec2D(-m_X, -m_Y);
}

/*
 * Overloading operator* and operator/
 * 
 * Return a new vec object with x and y scaled
 */

Vec2D Vec2D::operator*(double scalar) const
{
    return Vec2D(scalar * m_X, scalar * m_Y);
}

// Allows for, ex. 4 * vec

Vec2D operator*(double scalar, const Vec2D& vec) // Non-member of vec class
{
    return vec * scalar; // uses the operator* overload
}

Vec2D Vec2D::operator/(double scalar) const
{
    if (scalar == 0) // Scalar can not be 0
        throw std::runtime_error("ERROR: Division by zero\n");

    return Vec2D(m_X / scalar, m_Y / scalar);
}

/*
 * Overloading operator+
 * 
 * Add the x and y variables of this vec with another vecs x and y
 */

Vec2D Vec2D::operator+(const Vec2D& otherVec) const
{
    return Vec2D(m_X + otherVec.m_X, m_Y + otherVec.m_Y);
}

/*
 * Overloading operator-
 * 
 * Subtract the x and y variables of this vec with another vecs x and y
 */

Vec2D Vec2D::operator-(const Vec2D& otherVec) const
{
    return Vec2D(m_X - otherVec.m_X, m_Y - otherVec.m_Y);
}

/*
 * Overloading compound assignment operators
 * 
 * Allows for modifying the x and y member variables of this vec
 */

Vec2D& Vec2D::operator*=(double scalar)
{
    *this *= scalar; // uses the operator* overload
    return *this;
}

Vec2D& Vec2D::operator/=(double scalar)
{
    if (scalar == 0) // Scalar can not be 0
        throw std::runtime_error("ERROR: Division by zero\n");
    *this /= scalar; // uses the operator/ overload
    return *this;
}

Vec2D& Vec2D::operator+=(const Vec2D& otherVec)
{
    *this += otherVec;
    return *this;
}

Vec2D& Vec2D::operator-=(const Vec2D& otherVec)
{
    *this -= otherVec;
    return *this;
}

/*
 * Magnitude of a vector formula
 * 
 * mag = sqrt(x^2 + y^2)
 */

double Vec2D::magnitude() const
{
    return std::hypot(m_X, m_Y);
}

/*
 * Theory behind normalizing a vector
 * 
 * First find the magnitude, or length, of a vector
 * and if the magnitude is greater than 1
 * scale the x, y variables down, and return a new vec
 * else if magnitude is less than 1, the vector is already
 * normalized so return the original vec
 */

Vec2D Vec2D::normalize() const
{
    double mag = magnitude();
    if (mag > 1)
    {
        return Vec2D(m_X / mag, m_Y / mag);
    }
    return *this;
}

/*
 * Distance between two vectors
 * d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
 * 
 * return to a vec object calling this function
 */

double Vec2D::distance(const Vec2D& otherVec) const
{
    return (otherVec - * this).magnitude();
}

/*
 * Dot product 
 * 
 * vec1 = [-3, 4]
 * vec2 = [4, 5]
 * 
 * vec1 dot vec2 = -3 * 4 + 4 * 5 = -12 + 20 = 8
 */

double Vec2D::dot(const Vec2D& otherVec) const
{
    return m_X * otherVec.m_X + m_Y * otherVec.m_Y;
}

/*
 * Formula to find angle between two vectors, a and b
 * 
 * arccos(a dot b / |a| * |b|)
 */

double Vec2D::angle(const Vec2D& otherVec) const
{
    double thisMag = this->magnitude();
    double otherMag = otherVec.magnitude();
    double dotProd = dot(otherVec);

    return std::acos(dotProd / (thisMag * otherMag))
            * (180 / M_PI); // convert to degrees
}

/*
 * Formula for vector rotation
 * 
 * xRot = x * cos(angle) - y * cos(angle)
 * yRot = x * sin(angle) + y * cos(angle)
 */

Vec2D Vec2D::rotate(double angle) const 
{   
    angle *= (M_PI / 180); // switching angle to radians
    
    double cosine = std::cos(angle);
    double sine = std::sin(angle);
    
    return Vec2D(m_X * cosine - m_Y * sine, m_X * sine + m_Y * cosine);
}


/*
 * Projection formula
 * 
 * dot product of vec1 and vec2 / vec2 magnitude, or normalize vec2
 */

Vec2D Vec2D::projectTo(const Vec2D& otherVec) const
{
    Vec2D unitVec = otherVec.normalize(); // If otherVec has length > 1

    double otherDot = dot(unitVec); // Equivalent to this.dot(otherVec)

    return unitVec * otherDot;
}

/*
 * Reflection formula for vector
 * 
 * R = v - 2 * (v * n) * n
 */

Vec2D Vec2D::reflect(const Vec2D& otherVec) const
{
    return *this -2 * projectTo(otherVec);
}

/*
 * Overloading extraction operator
 * 
 * Call this function when << is used on class objects
 */

std::ostream& operator<<(std::ostream& out, const Vec2D& vec)
{
    out << std::setprecision(2) << std::fixed <<
            "X: " << vec.getX() << ", Y: " << vec.getY() << '\n';
    return out;
}