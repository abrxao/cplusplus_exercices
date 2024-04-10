#ifndef HEXAGON_H
#define HEXAGON_H

#include "RegularPolygon.h"

// Implement the hexagon class here. Note that its constructor should receive
// only the sideLength parameter.
class Hexagon : public RegularPolygon
{
public:
    explicit Hexagon(double sideLength);

    const double calcArea() override;
};


#endif
