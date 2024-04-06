#include <iostream>
#include "Triangle.h"
#include "Hexagon.h"

int main(int argc, char *argv[])
{
    double sideLength = 3.5;
    Triangle triangle(sideLength);
    Hexagon hexagon(sideLength);

    std::cout << "The total length of the triangle is " << triangle.calcTotalLength() << std::endl;
    std::cout << "The are of the triangle is " << triangle.calcArea() << std::endl;

    std::cout << "The total length of the hexagon is " << hexagon.calcTotalLength() << std::endl;
    std::cout << "The area of the hexagon is " << hexagon.calcArea() << std::endl;

    return 0;
}
