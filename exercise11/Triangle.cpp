#include "Triangle.h"

Triangle::Triangle(double sideLength) : RegularPolygon(3, sideLength) {}

double Triangle::calcArea() {
    return sideLength * calcHeight() / 2.0;
}
