#ifndef RAY_TRACING_IN_ONE_WEEKEND_BITMAP_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_BITMAP_HXX

#include <cstdint>
#include <memory>

#include <channel.hxx>
#include <color.hxx>

namespace pi
{

    class Bitmap
    {
    public:
        Bitmap(unsigned width, unsigned height);

        uint8_t &operator [](unsigned row, unsigned column, Channel channel);
        Color operator [](unsigned row, unsigned column) const;

        [[nodiscard]] auto width() const noexcept -> unsigned;
        [[nodiscard]] auto height() const noexcept -> unsigned;

    private:
        unsigned const width_;
        unsigned const height_;

        std::unique_ptr<uint8_t[]> bitmap_{};
    };

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_BITMAP_HXX
