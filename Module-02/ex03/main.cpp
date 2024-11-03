// https://www.desmos.com/calculator/gjwgytmdnh

#include <iostream>
#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);


int main( void ) 
{
    // https://www.desmos.com/calculator/4q4v4wxg3y

    Point A1(0.0f, 0.0f);
    Point B1(3.0f, 3.0f);
    Point C1(3.0f, 0.0f);
    Point P1(2.0f, 1.0f);
    Point P2(2.0f, 2.0f);

    std::cout << "A1: " << A1 << std::endl;
    std::cout << "B1: " << B1 << std::endl;
    std::cout << "C1: " << C1 << std::endl;
    std::cout << "P1: " << P1 << std::endl;
    std::cout << "P2: " << P2 << std::endl;

    if (bsp(A1, B1, C1, P1))
        std::cout << "P1 is inside the triangle ABC" << std::endl;
    else
        std::cout << "Test Case 1 FAIL: False" << std::endl;

    if (bsp(A1, B1, C1, P2))
        std::cout << "Test Case 2 FAIL: True" << std::endl;
    else
        std::cout << "P2 is on the edge of the triangle ABC" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    
    Point A2(4.0f, 4.4f);
    Point B2(9.0f, 3.0f);
    Point C2(7.0f, 8.0f);
    Point P3(6.2f, 5.6f);
    Point P4(6.4f, 7.8f);

    std::cout << "A: " << A2 << std::endl;
    std::cout << "B: " << B2 << std::endl;
    std::cout << "C: " << C2 << std::endl;
    std::cout << "P: " << P3 << std::endl;

    if (bsp(A2, B2, C2, P3))
        std::cout << "P3 is inside the triangle ABC" << std::endl;
    else
        std::cout << "Test Case 3 FAIL: False" << std::endl;
    
    if (bsp(A2, B2, C2, P4))
        std::cout << "Test Case 4 FAIL: True" << std::endl;
    else
        std::cout << "P4 is outside the triangle ABC" << std::endl;
    
    std::cout << std::endl;
    
    return 0;
}