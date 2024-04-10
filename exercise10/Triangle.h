#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "RegularPolygon.h"

// Implement the triangle class here. Note that its constructor should receive
// only the sideLength parameter.
class Triangle : public RegularPolygon {
    public:
        Triangle(double sideLength) : RegularPolygon(3, sideLength) {};
        double calcArea() override;

};

#endif
