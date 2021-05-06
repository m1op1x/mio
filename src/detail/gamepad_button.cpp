#include <mio/detail/gamepad_button.hpp>

#include <mio/exception.hpp>

namespace mio::detail
{
    gamepad_button convert_gamepad_button(SDL_GameControllerButton button)
    {
        switch (button)
        {
            case SDL_CONTROLLER_BUTTON_A:
            {
                return gamepad_button::a;
            }
            case SDL_CONTROLLER_BUTTON_B:
            {
                return gamepad_button::b;
            }
            case SDL_CONTROLLER_BUTTON_X:
            {
                return gamepad_button::x;
            }
            case SDL_CONTROLLER_BUTTON_Y:
            {
                return gamepad_button::y;
            }
            case SDL_CONTROLLER_BUTTON_BACK:
            {
                return gamepad_button::back;
            }
            case SDL_CONTROLLER_BUTTON_GUIDE:
            {
                return gamepad_button::guide;
            }
            case SDL_CONTROLLER_BUTTON_START:
            {
                return gamepad_button::start;
            }
            case SDL_CONTROLLER_BUTTON_LEFTSTICK:
            {
                return gamepad_button::left_thumb;
            }
            case SDL_CONTROLLER_BUTTON_RIGHTSTICK:
            {
                return gamepad_button::right_thumb;
            }
            case SDL_CONTROLLER_BUTTON_LEFTSHOULDER:
            {
                return gamepad_button::left_bumper;
            }
            case SDL_CONTROLLER_BUTTON_RIGHTSHOULDER:
            {
                return gamepad_button::right_bumper;
            }
            case SDL_CONTROLLER_BUTTON_DPAD_UP:
            {
                return gamepad_button::dpad_up;
            }
            case SDL_CONTROLLER_BUTTON_DPAD_DOWN:
            {
                return gamepad_button::dpad_down;
            }
            case SDL_CONTROLLER_BUTTON_DPAD_LEFT:
            {
                return gamepad_button::dpad_left;
            }
            case SDL_CONTROLLER_BUTTON_DPAD_RIGHT:
            {
                return gamepad_button::dpad_right;
            }
            default:
            {
                throw exception("Invalid gamepad button");
            }
        }
    }

    SDL_GameControllerButton convert_gamepad_button(gamepad_button button)
    {
        switch (button)
        {
            case gamepad_button::a:
            {
                return SDL_CONTROLLER_BUTTON_A;
            }
            case gamepad_button::b:
            {
                return SDL_CONTROLLER_BUTTON_B;
            }
            case gamepad_button::x:
            {
                return SDL_CONTROLLER_BUTTON_X;
            }
            case gamepad_button::y:
            {
                return SDL_CONTROLLER_BUTTON_Y;
            }
            case gamepad_button::back:
            {
                return SDL_CONTROLLER_BUTTON_BACK;
            }
            case gamepad_button::guide:
            {
                return SDL_CONTROLLER_BUTTON_GUIDE;
            }
            case gamepad_button::start:
            {
                return SDL_CONTROLLER_BUTTON_START;
            }
            case gamepad_button::left_thumb:
            {
                return SDL_CONTROLLER_BUTTON_LEFTSTICK;
            }
            case gamepad_button::right_thumb:
            {
                return SDL_CONTROLLER_BUTTON_RIGHTSTICK;
            }
            case gamepad_button::left_bumper:
            {
                return SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
            }
            case gamepad_button::right_bumper:
            {
                return SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
            }
            case gamepad_button::dpad_up:
            {
                return SDL_CONTROLLER_BUTTON_DPAD_UP;
            }
            case gamepad_button::dpad_down:
            {
                return SDL_CONTROLLER_BUTTON_DPAD_DOWN;
            }
            case gamepad_button::dpad_left:
            {
                return SDL_CONTROLLER_BUTTON_DPAD_LEFT;
            }
            case gamepad_button::dpad_right:
            {
                return SDL_CONTROLLER_BUTTON_DPAD_RIGHT;
            }
            default:
            {
                throw exception("Invalid gamepad button");
            }
        }
    }
}
