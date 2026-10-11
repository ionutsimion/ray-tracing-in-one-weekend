#ifndef RAY_TRACING_IN_ONE_WEEKEND_RENDERER_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_RENDERER_HXX

#include <bitmap.hxx>

namespace pi
{

    class Renderer
    {
    public:
        virtual ~Renderer() = default;

        virtual auto render_frame(Bitmap const &) const -> void = 0;
    };

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_RENDERER_HXX
