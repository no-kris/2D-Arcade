#ifndef VEC2D_H
#define VEC2D_H

class Vec2D
{
public:
    Vec2D();
    Vec2D(double x, double y);
    virtual ~Vec2D();

    // Setters

    inline void
    setX(double x)
    {
        m_X = x;
    }

    inline void
    setY(double y)
    {
        m_Y = y;
    }

    // Getters

    inline double
    getX() const
    {
        return m_X;
    }

    inline double
    getY() const
    {
        return m_Y;
    }

    // operator overloading

    bool operator==(const Vec2D& otherVec) const;
    bool operator!=(const Vec2D& otherVec) const;

    Vec2D operator-() const;
    Vec2D operator*(double scalar) const;
    Vec2D operator/(double scalar) const;
    Vec2D operator+(const Vec2D& otherVec) const;
    Vec2D operator-(const Vec2D& otherVec) const;

    Vec2D& operator*=(double scalar);
    Vec2D& operator/=(double scalar);
    Vec2D& operator+=(const Vec2D& otherVec);
    Vec2D& operator-=(const Vec2D& otherVec);

    // Methods

    double squares() const;
    double magnitude() const;

    Vec2D normalize() const;

    double distance(const Vec2D& otherVec) const;
    double dot(const Vec2D& otherVec) const;
    double angle(const Vec2D& otherVec) const;
    Vec2D rotate(double angle) const;
    
    Vec2D projectTo(const Vec2D& otherVec) const;
    Vec2D reflect(const Vec2D& otherVec) const;
    
    

private:
    double m_X;
    double m_Y;
};

Vec2D operator*(double scalar, const Vec2D& vec);

std::ostream& operator<<(std::ostream& out, const Vec2D& vec);

#endif /* VEC2D_H */

