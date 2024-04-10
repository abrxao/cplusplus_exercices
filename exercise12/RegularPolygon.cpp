#include "RegularPolygon.h"
#include <cmath>

RegularPolygon::RegularPolygon(unsigned int numSides, double sideLength) : numSides(numSides), sideLength(sideLength) {}


const double RegularPolygon::calcTotalLength() {
    return numSides * sideLength;
}

const double RegularPolygon::calcHeight() {
    return std::sqrt(3) * sideLength / 2.0;
}
