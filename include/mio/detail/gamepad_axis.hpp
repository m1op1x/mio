#pragma once

#include <mio/gamepad_axis.hpp>
#include <SDL_gamecontroller.h>

namespace mio::detail
{
    gamepad_axis convert_gamepad_axis(SDL_GameControllerAxis axis);

    SDL_GameControllerAxis convert_gamepad_axis(gamepad_axis axis);

    float normalize_gamepad_axis(Sint16 position);
}
