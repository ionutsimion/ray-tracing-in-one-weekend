include(CTest)

list(APPEND CMAKE_MODULE_PATH ${Catch2_SOURCE_DIR}/extras)

include(Catch)

add_executable(ray-tracing-in-one-weekend-unit-tests unit/main.cxx)

target_link_libraries(ray-tracing-in-one-weekend-unit-tests PRIVATE Catch2::Catch2)

target_compile_features(ray-tracing-in-one-weekend-unit-tests PRIVATE cxx_std_23)

catch_discover_tests(ray-tracing-in-one-weekend-unit-tests)
