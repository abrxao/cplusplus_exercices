#define CONFIG_CATCH_MAIN
#include "catch.hpp"
#include "Triangle.h"
#include <cmath>

TEST_CASE("Triangle class tests", "[Triangle]") {
    const double sideLength = 2.5;
    Triangle Trian1(sideLength);

    // Note that here we use the calcHeight method, but we assume it is correct
    // because it was aready tested in the test_RegularPolygon file
    const double expectedArea = sideLength * Trian1.calcHeight()/2;

    // Test that the calcArea method returns the expected correct value
    SECTION( "Verifing if value calculate by calcArea() is equal to expectedArea" ) {
        REQUIRE(Trian1.calcArea() == expectedArea);
    }
    const double totalLengthExpected = sideLength*3;

    SECTION( "Verifing if value calculate by calcTotalLength() is equal to totalLengthExpected" ) {
        REQUIRE(Trian1.calcTotalLength() == totalLengthExpected);
    }

    const double expectedHeight = std::sqrt(3) * sideLength / 2.0;
    SECTION( "Verifing if value calculate by calcHeight() is equal to expectHeight" ) {
        REQUIRE(Trian1.calcTotalLength() == totalLengthExpected);
    }

    SECTION("Verifing if value returned by getNumSides() is equal to 3"){
        REQUIRE(Trian1.getNumSides() == 3);
    }
}
