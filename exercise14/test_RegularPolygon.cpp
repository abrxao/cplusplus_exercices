#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include "RegularPolygon.h"
#include <cmath>

class Dummy_RegularPolygon : public RegularPolygon {
public:
    // Inherit RegularPolygon constructors
    using RegularPolygon::RegularPolygon;

    double calcArea() const override {
        return 0;
    }
};


// TIP: We can break the TEST_CASE into sections and each section is run once.
// The code outside the sections is run again for each section. Note that it
// would give different values if we were generating random values, but here we
// just set a variable to a fixed value.
TEST_CASE("Test the RegularPolygon class", "[RegularPolygon]") {
    double sideLength = 2.5;

    SECTION("Test getNumSides") {
        // Test for RegularPolygon with different number of sides
        for(auto numSides : {4, 5, 6, 20}) {
            Dummy_RegularPolygon obj(numSides, sideLength);
            REQUIRE(obj.getNumSides() == numSides);
        }
    }

    SECTION("Test calcHeight") {
        // The polygon height does not depend on the number of sides
        double expectedHeight = sideLength * std::sqrt(3) / 2.0;

        for(auto numSides : {4, 5, 6, 20}) {
            Dummy_RegularPolygon obj(numSides, sideLength);
            REQUIRE(obj.calcHeight() == expectedHeight);
        }
    }

    SECTION("Test calcTotalLength") {
        for(auto numSides : {4, 5, 6, 20}) {
            Dummy_RegularPolygon obj(numSides, sideLength);
            REQUIRE(obj.calcTotalLength() == numSides * sideLength);
        }
    }
}
