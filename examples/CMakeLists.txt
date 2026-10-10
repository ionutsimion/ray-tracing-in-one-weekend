add_executable(ppm-renderer ppm_renderer.cxx)

target_compile_features(ppm-renderer PUBLIC cxx_std_23)

target_link_libraries(ppm-renderer PRIVATE ray-tracing-lib)

include_directories(include)
