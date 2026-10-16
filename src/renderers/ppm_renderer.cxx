#include <iostream>

#include <lib/bitmap.hxx>
#include <renderers/ppm_renderer.hxx>

pi::PPMRenderer::PPMRenderer(std::ostream &stream) noexcept
: stream_{ stream }
{
}

auto pi::PPMRenderer::render_frame(Bitmap const &bitmap) const -> void
{
    auto const width = bitmap.width();
    auto const height = bitmap.height();

    std::println(stream_, "P3");
    std::println(stream_, "{} {}", width, height);
    std::println(stream_, "255");

    for (auto row = 0; row < bitmap.height(); ++row)
    {
        std::print(std::clog, "\rScanning lines... {:5.2f}%.", static_cast<pi::real>(row) * 100.0 / (height - 1.0));

        for (auto col = 0; col < width; ++col)
        {
            auto const [r, g, b] = to_8bit(bitmap[row, col]);

            std::println(stream_, "{:d} {:d} {:d}", r, g, b);
        }
    }

    std::println(std::clog, " Complete!");
}
