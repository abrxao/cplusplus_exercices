#include <catch.hpp>
#include "Hexagon.h"
#include <cmath>

TEST_CASE("Test the Hexagon class", "[Hexagon]") {
    double sideLength = 2.5;
    Hexagon obj(sideLength);

    // Note that here we use the calcHeight method, but we assume it is correct
    // because it was aready tested in the test_RegularPolygon file
    double expectedArea = 3 * sideLength * obj.calcHeight();

    // Test that the calcArea method returns the expected correct value
    REQUIRE(obj.calcArea() == expectedArea);
}
