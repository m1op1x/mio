#pragma once

#include <mio/gamepad_button.hpp>
#include <SDL_gamecontroller.h>

namespace mio::detail
{
    gamepad_button convert_gamepad_button(SDL_GameControllerButton button);

    SDL_GameControllerButton convert_gamepad_button(gamepad_button button);
}
