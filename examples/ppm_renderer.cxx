#include <renderers/ppm_renderer.hxx>

#include <cmath>
#include <iostream>
#include <fstream>

#include <bitmap.hxx>
#include <color.hxx>

int main(int const argc, const char* const argv[])
{
    auto constexpr image_width = 512;
    auto constexpr image_height = 512;

    pi::Bitmap bitmap(image_width, image_height);
    for (auto row = 0; row < image_height; ++row)
    {
        auto const g = static_cast<pi::real>(row) / static_cast<pi::real>(image_height - 1);
        for (auto col = 0; col < image_width; ++col)
        {
            auto const r = static_cast<pi::real>(col) / static_cast<pi::real>(image_width - 1);
            bitmap[row, col, pi::Channel::Red] = static_cast<std::uint8_t>(r * 255.0);
            bitmap[row, col, pi::Channel::Green] = static_cast<std::uint8_t>(g * 255.0);
            bitmap[row, col, pi::Channel::Blue] = static_cast<std::uint8_t>(std::sqrt(r * g) * 255.0);
        }
    }

    std::ofstream os{};
    if (argc > 1)
        os.open(argv[1]);

    pi::PPMRenderer const renderer(os.is_open() ? os : std::cout);
    renderer.render_frame(bitmap);

    os.close();

    return 0;
}
