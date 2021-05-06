#include <mio/detail/gamepad_axis.hpp>

#include <mio/exception.hpp>
#include <limits>

namespace mio::detail
{
    gamepad_axis convert_gamepad_axis(SDL_GameControllerAxis axis)
    {
        switch (axis)
        {
            case SDL_CONTROLLER_AXIS_LEFTX:
            {
                return gamepad_axis::left_x;
            }
            case SDL_CONTROLLER_AXIS_LEFTY:
            {
                return gamepad_axis::left_y;
            }
            case SDL_CONTROLLER_AXIS_RIGHTX:
            {
                return gamepad_axis::right_x;
            }
            case SDL_CONTROLLER_AXIS_RIGHTY:
            {
                return gamepad_axis::right_y;
            }
            case SDL_CONTROLLER_AXIS_TRIGGERLEFT:
            {
                return gamepad_axis::left_trigger;
            }
            case SDL_CONTROLLER_AXIS_TRIGGERRIGHT:
            {
                return gamepad_axis::right_trigger;
            }
            default:
            {
                throw exception("Invalid gamepad axis");
            }
        }
    }

    SDL_GameControllerAxis convert_gamepad_axis(gamepad_axis axis)
    {
        switch (axis)
        {
            case gamepad_axis::left_x:
            {
                return SDL_CONTROLLER_AXIS_LEFTX;
            }
            case gamepad_axis::left_y:
            {
                return SDL_CONTROLLER_AXIS_LEFTY;
            }
            case gamepad_axis::right_x:
            {
                return SDL_CONTROLLER_AXIS_RIGHTX;
            }
            case gamepad_axis::right_y:
            {
                return SDL_CONTROLLER_AXIS_RIGHTY;
            }
            case gamepad_axis::left_trigger:
            {
                return SDL_CONTROLLER_AXIS_TRIGGERLEFT;
            }
            case gamepad_axis::right_trigger:
            {
                return SDL_CONTROLLER_AXIS_TRIGGERRIGHT;
            }
            default:
            {
                throw exception("Invalid gamepad axis");
            }
        }
    }

    float normalize_gamepad_axis(Sint16 position)
    {
        return position < 0
            ? -static_cast<float>(position) / std::numeric_limits<Sint16>::min()
            :  static_cast<float>(position) / std::numeric_limits<Sint16>::max();
    }
}
