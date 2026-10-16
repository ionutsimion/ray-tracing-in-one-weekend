#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_adapters.hpp>
#include <catch2/generators/catch_generators_random.hpp>

#include <lib/color.hxx>

#include "../../cmake-build-release/_deps/catch2-src/src/catch2/matchers/catch_matchers.hpp"

TEST_CASE("Real to 8bit", "[color]") {
    SECTION("0.0 is converted to 0")
    {
        REQUIRE(pi::to_8bit(0.0) == 0u);
    }

    SECTION("1.0 is converted to 255")
    {
        REQUIRE(pi::to_8bit(1.0) == 255u);
    }

    SECTION("Random between 0.0 and 1.0")
    {
        auto const color = GENERATE(take(1024, random(0.0, 1.0)));
        auto const color_8bit = pi::to_8bit(color);

        REQUIRE(color_8bit >= 0u);
        REQUIRE(color_8bit <= 255u);
        REQUIRE_THAT(color_8bit / 255.0, Catch::Matchers::WithinAbs(color, 1.0/255.0));
    }
}

TEST_CASE("Color to 8bit", "[color]")
{
    SECTION("Black is converted to (0, 0, 0)")
    {
        auto constexpr color = pi::Color(0.0, 0.0, 0.0);

        REQUIRE(pi::to_8bit(color) == std::make_tuple(0u, 0u, 0u));
    }

    SECTION("White is converted to (255, 255, 255)")
    {
        auto constexpr color = pi::Color(1.0, 1.0, 1.0);

        REQUIRE(pi::to_8bit(color) == std::make_tuple(255u, 255u, 255u));
    }

    SECTION("Random color")
    {
    }
}
