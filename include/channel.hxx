#ifndef RAY_TRACING_IN_ONE_WEEKEND_CHANNEL_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_CHANNEL_HXX

#include <chrono>
#include <cstdint>

using namespace std::literals;

namespace pi
{

    enum class Channel: std::uint8_t
    {
        Red     = 0u,
        Green   = 1u,
        Blue    = 2u
    };

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_CHANNEL_HXX
