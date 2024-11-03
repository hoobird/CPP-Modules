#include "Point.hpp"

Point::Point()
{
    this->x = Fixed(0);
    this->y = Fixed(0);
}

Point::Point(float x, float y)
{
    this->x = Fixed(x);
    this->y = Fixed(y);
}

Point::Point(const Point &other)
{
    this->x = other.getX();
    this->y = other.getY();
}

Point& Point::operator=(const Point &other)
{
    if (this != &other)
    {
        this->x = other.getX();
        this->y = other.getY();
    }
    return *this;
}

Point::~Point()
{
    
}

Fixed Point::getX() const
{
    return this->x;
}

Fixed Point::getY() const
{
    return this->y;
}

Fixed Point::crossProduct(Point const &A, Point const &B, Point const &P) const // AB X AP
{
    float ABx = B.getX().toFloat() - A.getX().toFloat();
    float ABy = B.getY().toFloat() - A.getY().toFloat();
    float APx = P.getX().toFloat() - A.getX().toFloat();
    float APy = P.getY().toFloat() - A.getY().toFloat();

    return Fixed(ABx * APy - ABy * APx);
}

std::ostream& operator<<(std::ostream &os, const Point &point)
{
    os << "X: " << point.getX() << ", Y: " << point.getY();
    return os;
}
