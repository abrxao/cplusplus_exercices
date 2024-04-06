#include "Triangle.h"

Triangle::Triangle(double sideLength) : RegularPolygon(3, sideLength) {}

double Triangle::calcArea() const {
    return sideLength * calcHeight() / 2.0;
}
