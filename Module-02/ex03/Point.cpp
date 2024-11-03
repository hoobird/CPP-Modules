#include "Point.h"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(const float x, const float y)
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

Fixed Point::crossProduct(Point const &a, Point const &b, Point const &P) const
{
    
}
