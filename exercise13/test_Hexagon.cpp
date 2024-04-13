#define CONFIG_CATCH_MAIN
#include "catch.hpp"
#include "Hexagon.h"
#include <cmath>

TEST_CASE("Hexagon class tests", "[Hexagon]") {
    const double sideLength = 2.5;
    Hexagon Hex1(sideLength);

    // Note that here we use the calcHeight method, but we assume it is correct
    // because it was aready tested in the test_RegularPolygon file
    const double expectedArea = sideLength * Hex1.calcHeight()*3;

    // Test that the calcArea method returns the expected correct value
    SECTION( "Verifing if value calculate by calcArea() is equal to expectedArea" ) {
        REQUIRE(Hex1.calcArea() == expectedArea);
    }
    const double totalLengthExpected = sideLength*6;

    SECTION( "Verifing if value calculate by calcTotalLength() is equal to totalLengthExpected" ) {
        REQUIRE(Hex1.calcTotalLength() == totalLengthExpected);
    }

    const double expectedHeight = std::sqrt(3) * sideLength / 2.0;;
    SECTION( "Verifing if value calculate by calcHeight() is equal to expectHeight" ) {
        REQUIRE(Hex1.calcTotalLength() == totalLengthExpected);
    }

    SECTION("Verifing if value returned by getNumSides() is equal to 6"){
        REQUIRE(Hex1.getNumSides() == 6);
    }
}
