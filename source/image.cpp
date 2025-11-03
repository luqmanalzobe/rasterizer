#include <rasterizer/image.hpp>

#define STB_IMAGE_IMPLEMENTATION
#include <rasterizer/stb_image.h>

namespace rasterizer
{
    image<color4ub> load_image(std::filesystem::path const& path)
    {
        image<color4ub> result;
        int channels = 0;

        // On Windows, stbi_load expects const char*, not wide chars.
        stbi_uc* data = stbi_load(
            path.string().c_str(),
            reinterpret_cast<int*>(&result.width),
            reinterpret_cast<int*>(&result.height),
            &channels,
            4  // force RGBA
        );

        result.pixels.reset(reinterpret_cast<color4ub*>(data));
        return result;
    }
}
