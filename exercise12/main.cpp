#include <iostream>
#include "Triangle.h"
#include "Hexagon.h"
#include <vector>
#include <memory> // For unique_ptr

int main(int argc, char *argv[])
{
    std::vector<std::unique_ptr<RegularPolygon>> vec;

    vec.push_back(std::make_unique<Triangle>(3.55));
    vec.push_back(std::make_unique<Triangle>(1.44));
    vec.push_back(std::make_unique<Hexagon>(3.55));
    vec.push_back(std::make_unique<Hexagon>(1.44));


    // Now we call the calcArea method for each regular polygon. Even though the
    // pointers are of type RegularPolygon, the correct implementation in either
    // Triangle or the hexagon class will be used depending on the actual object
    // pointed by the pointer.
    for(auto& polygon : vec) {
        std::cout << "The polygon has " << polygon->getNumSides() << " and its area is " << polygon->calcArea() << std::endl;
    }

    return 0;
}
