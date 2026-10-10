#include <cmath>
#include <iostream>
#include <print>

#include <bitmap.hxx>
#include <color.hxx>

int main(int const, const char* const[])
{
    auto constexpr image_width = 1024;
    auto constexpr image_height = 1024;

    pi::Bitmap bitmap(image_width, image_height);
    for (auto row = 0; row < image_height; ++row)
    {
        auto const g = static_cast<double>(row) / static_cast<double>(image_height - 1);
        for (auto col = 0; col < image_width; ++col)
        {
            auto const r = static_cast<double>(col) / static_cast<double>(image_width - 1);
            bitmap[row, col, pi::Channel::Red] = static_cast<std::uint8_t>(r * 255);
            bitmap[row, col, pi::Channel::Green] = static_cast<std::uint8_t>(g * 255);
            bitmap[row, col, pi::Channel::Blue] = static_cast<std::uint8_t>(std::sqrt(r * g));
        }
    }

    std::println("P3");
    std::println("{} {}", image_width, image_height);
    std::println("255");

    for (auto row = 0; row < image_height; ++row)
    {
        std::print(std::clog, "\rScanning lines... {:5.2}%", static_cast<double>(row) * 100.0 / (image_height - 1.0));

        for (auto col = 0; col < image_width; ++col)
        {
            auto const color = bitmap[row, col];

            std::println("{:d} {:d} {:d}", pi::as<int>(color.r), pi::as<int>(color.g), pi::as<int>(color.b));
        }
    }

    std::print(std::clog, "\rDone.                   \n");

    return 0;
}
