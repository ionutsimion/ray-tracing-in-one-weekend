#include <cmath>
#include <print>

int main(int const, const char* const[])
{
    auto constexpr image_width = 1024;
    auto constexpr image_height = 1024;

    std::println("P3");
    std::println("{} {}", image_width, image_height);
    std::println("255");

    for (auto row = 0; row < image_height; ++row)
        for (auto col = 0; col < image_width; ++col)
        {
            auto const r = static_cast<double>(col) / static_cast<double>(image_width - 1);
            auto const g = static_cast<double>(row) / static_cast<double>(image_height - 1);
            auto const b = std::sqrt(r * g);

            std::println("{:d} {:d} {:d}"
                       , static_cast<int>(255.0 * r)
                       , static_cast<int>(255.0 * g)
                       , static_cast<int>(255.0 * b));
        }

    return 0;
}
