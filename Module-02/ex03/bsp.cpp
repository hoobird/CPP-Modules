
# include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    float   crossABAP = a.crossProduct(b, point).toFloat();
    float   crossBCBP = b.crossProduct(c, point).toFloat();
    float   crossCACP = c.crossProduct(a, point).toFloat();

    if ((crossABAP > 0 && crossBCBP > 0 && crossCACP > 0) || (crossABAP < 0 && crossBCBP < 0 && crossCACP < 0))
        return true;
    return false;  
}


