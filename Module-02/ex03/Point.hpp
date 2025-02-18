#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed x;
        Fixed y;

    public:
        Point();
        Point(float x, float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;

        Fixed   crossProduct(Point const &B, Point const &P) const;  // AB X AP
};

std::ostream& operator<<(std::ostream &os, const Point &point);

#endif