#include <catch2/catch_session.hpp>

int main(int const argc, const char *const argv[])
{
    return Catch::Session().run(argc, argv);
}
