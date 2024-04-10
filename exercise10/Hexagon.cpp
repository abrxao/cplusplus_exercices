#include "Hexagon.h"
#include "math.h"

double Hexagon::calcArea(){
    double perimeter = sideLength*numSides;
    double alpha = 2*M_PI/numSides;
    double polygonApothem = (sideLength)/tan(alpha);
    return (polygonApothem*perimeter/2);
}