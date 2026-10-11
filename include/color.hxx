#ifndef RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX

#include <concepts>

#include <types.hxx>

namespace pi
{

    struct Color
    {
        Color(real const red, real const green, real const blue)
            : r(red)
            , g(green)
            , b(blue)
        {
        }

        Color(std::uint8_t const red, std::uint8_t const green, std::uint8_t const blue)
            : r(red)
            , g(green)
            , b(blue)
        {
        }

        real r{};
        real g{};
        real b{};

        auto set_r(real const red)
        {
            r = red;
        }

        auto set_g(real const green)
        {
            g = green;
        }

        auto set_b(real const blue)
        {
            b = blue;
        }
    };

    template <typename ReturnType>
    auto as(real const x) -> ReturnType
    {
        return static_cast<ReturnType>(x);
    }

    template <std::integral>
    auto as(real const x) -> int
    {
        return static_cast<int>(x * 255.0);
    }

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX
