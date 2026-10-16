cmake_minimum_required(VERSION 4.2)

project(ray-tracing-in-one-weekend VERSION 0.1.0 DESCRIPTION "Ray Tracing in One Weekend" LANGUAGES CXX)

include(cmake/dependencies.cmake)
include(cmake/options.cmake)

enable_testing()

add_library(
        ray-tracing-lib
        STATIC
            src/lib/bitmap.cxx
        src/renderers/ppm_renderer.cxx)

target_include_directories(ray-tracing-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_features(ray-tracing-lib PUBLIC cxx_std_23)

add_executable(ray-tracing-in-one-weekend src/main.cxx)

target_compile_features(ray-tracing-in-one-weekend PUBLIC cxx_std_23)

if(RAY_TRACING_IN_ONE_WEEKEND_BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(RAY_TRACING_IN_ONE_WEEKEND_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
