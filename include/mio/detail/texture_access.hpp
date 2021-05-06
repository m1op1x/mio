#pragma once

#include <mio/texture_access.hpp>
#include <SDL_render.h>

namespace mio::detail
{
    SDL_TextureAccess convert_texture_access(texture_access access);
}
