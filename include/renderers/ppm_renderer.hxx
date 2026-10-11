#ifndef RAY_TRACING_IN_ONE_WEEKEND_PPM_RENDERER_HXX
#define RAY_TRACING_IN_ONE_WEEKEND_PPM_RENDERER_HXX

#include <renderers/renderer.hxx>

namespace pi
{

    class PPMRenderer: public Renderer
    {
    public:
        using Renderer::Renderer;

        explicit PPMRenderer(std::ostream &stream) noexcept;

        auto render_frame(Bitmap const &) const -> void override;

    private:
        std::ostream &stream_;
    };

}

#endif //RAY_TRACING_IN_ONE_WEEKEND_PPM_RENDERER_HXX
