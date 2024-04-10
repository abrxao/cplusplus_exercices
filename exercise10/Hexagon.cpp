#include "Hexagon.h"
#include "math.h"

double Hexagon::calcArea(){
    return (calcHeight()*sideLength*numSides/2);
}