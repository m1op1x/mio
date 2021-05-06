#pragma once

#include <string>
#include <memory>

struct SDL_Texture;

namespace mio
{
    enum class texture_access
    {
        static_,
        dynamic,
        target
    };

}
