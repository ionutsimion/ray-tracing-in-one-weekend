#ifndef RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX

#include <tuple>

#include <lib/common.hxx>

namespace pi
{

    struct Color
    {
        real r{};
        real g{};
        real b{};
    };

    [[nodiscard]] auto constexpr to_8bit(real color) noexcept -> uint8_t
    {
        return static_cast<uint8_t>(color * 255.0);
    }

    [[nodiscard]] auto constexpr to_8bit(Color const &color) noexcept -> std::tuple<uint8_t, uint8_t, uint8_t>
    {
        return std::make_tuple(to_8bit(color.r), to_8bit(color.g), to_8bit(color.b));
    }

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_COLOR_HXX
