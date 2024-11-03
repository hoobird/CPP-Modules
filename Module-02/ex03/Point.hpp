#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float x, const float y);
        Point(const Point &other);
        Point &operator=(const Point &other);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;

        Fixed   crossProduct(Point const &A, Point const &B, Point const &P) const;  // AB X AP
}

#endif