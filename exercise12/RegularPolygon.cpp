#include "RegularPolygon.h"
#include <cmath>

RegularPolygon::RegularPolygon(unsigned int numSides, double sideLength) : numSides(numSides), sideLength(sideLength) {}


double RegularPolygon::calcTotalLength() {
    return numSides * sideLength;
}

double RegularPolygon::calcHeight() {
    return std::sqrt(3) * sideLength / 2.0;
}
