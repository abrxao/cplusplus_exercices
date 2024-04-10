#include "Triangle.h"
#include <math.h>

double Triangle::calcArea(){
    return (sideLength*sideLength*sqrt(3)/4);
}