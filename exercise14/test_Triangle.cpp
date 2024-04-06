#include <catch.hpp>
#include "Triangle.h"
#include <cmath>

TEST_CASE("Test the Triangle class", "[Triangle]") {
    double sideLength = 2.5;
    Triangle obj(sideLength);

    // Note that here we use the calcHeight method, but we assume it is correct
    // because it was aready tested in the test_RegularPolygon file
    double expectedArea = sideLength * obj.calcHeight() / 2;

    // Test that the calcArea method returns the expected correct value
    REQUIRE(obj.calcArea() == expectedArea);
}
