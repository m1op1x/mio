#pragma once

#include <mio/scancode.hpp>
#include <SDL_scancode.h>

namespace mio::detail
{
    scancode convert_scancode(SDL_Scancode scancode);

    SDL_Scancode convert_scancode(scancode key);
}
