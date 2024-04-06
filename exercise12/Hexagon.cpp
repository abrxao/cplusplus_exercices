#include "Hexagon.h"

Hexagon::Hexagon(double sideLength) : RegularPolygon(6, sideLength) {}

double Hexagon::calcArea() {
    return 6 * sideLength * calcHeight() / 2.0;
}
