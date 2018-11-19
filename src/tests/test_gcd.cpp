#include "../gcd.h"
#include "catch.hpp"

using namespace Competitive;

TEST_CASE("GDC tests")
{
    REQUIRE(gcd(92, 150) == 2);
    REQUIRE(gcd(127, 350) == 1);
    REQUIRE(gcd(415, 175) == 5);
    REQUIRE(gcd(453, 304) == 1);
    REQUIRE(gcd(453 * 23, 304 * 23) == 23);
}

