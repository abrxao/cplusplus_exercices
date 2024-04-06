#include <iostream>
#include "Triangle.h"
#include "Hexagon.h"
#include <vector>
#include <memory> // For unique_ptr

int main(int argc, char *argv[])
{
    std::vector<std::unique_ptr<RegularPolygon>> vec;

    // TODO: Add a few triangle and hexagons of varying side length to vec



    // Now we call the calcArea method for each regular polygon. Even though the
    // pointers are of type RegularPolygon, the correct implementation in either
    // Triangle or the hexagon class will be used depending on the actual object
    // pointed by the pointer.
    for(auto& polygon : vec) {
        std::cout << "The polygon has " << polygon->getNumSides() << " and its area is " << polygon->calcArea() << std::endl;
    }

    return 0;
}
