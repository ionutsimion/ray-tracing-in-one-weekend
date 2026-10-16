#include <lib/bitmap.hxx>

pi::Bitmap::Bitmap(unsigned const width, unsigned const height)
    : width_(width)
    , height_(height)
    , bitmap_(std::make_unique<uint8_t[]>(width_ * height_ * 3u))
{
}

uint8_t &pi::Bitmap::operator [](unsigned const row, unsigned const column, Channel const channel)
{
    auto const pointer = (row * width_ + column) * 3u;
    auto const channel_index = channel == Channel::Green ? 1 : channel == Channel::Blue ? 2 : 0;

    return bitmap_[pointer + channel_index];
}

pi::Color pi::Bitmap::operator[](unsigned const row, unsigned const column) const
{
    auto const pointer = (row * width_ + column) * 3u;

    return
    {
        bitmap_[pointer] / 255.0
      , bitmap_[pointer + 1u] / 255.0
      , bitmap_[pointer + 2u] / 255.0
    };
}

auto pi::Bitmap::width() const noexcept -> unsigned
{
    return width_;
}

auto pi::Bitmap::height() const noexcept -> unsigned
{
    return height_;
}
