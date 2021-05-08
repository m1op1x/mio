#include <mio/detail/gamepad.hpp>

#include <SDL_gamecontroller.h>

namespace mio::detail
{
    int to_joystick_index(int gamepad_index)
    {
        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            if (SDL_IsGameController(i))
            {
                if (gamepad_index-- == 0)
                {
                    return i;
                }
            }
        }
        return SDL_NumJoysticks();
    }

    int to_gamepad_index(int joystick_index)
    {
        int result = 0;
        for (int i = 0; i < joystick_index; i++)
        {
            if (SDL_IsGameController(i))
            {
                result++;
            }
        }
        return result;
    }
}
