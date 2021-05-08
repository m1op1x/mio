#include <mio/gamepad.hpp>

#include <mio/detail/gamepad_button.hpp>
#include <mio/detail/gamepad_axis.hpp>
#include <mio/detail/gamepad.hpp>
#include <mio/exception.hpp>
#include <SDL_gamecontroller.h>

namespace mio
{
    int gamepad::device_count()
    {
        return detail::to_gamepad_index(SDL_NumJoysticks());
    }

    gamepad::gamepad(int device_index)
        : controller_(nullptr)
    {
        controller_ =
        {
            SDL_GameControllerOpen(detail::to_joystick_index(device_index)),
            SDL_GameControllerClose
        };

        if (controller_ == nullptr)
        {
            throw sdl_error();
        }
    }

    gamepad::gamepad(SDL_GameController* controller)
        : controller_(controller, SDL_GameControllerClose)
    {
        if (controller_ == nullptr)
        {
            throw exception("Invalid game controller");
        }
    }

    SDL_GameController* gamepad::native_handle() const
    {
        return controller_.get();
    }

    int gamepad::instance_id() const
    {
        SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller_.get());
        if (joystick == nullptr)
        {
            throw sdl_error();
        }

        SDL_JoystickID instance_id = SDL_JoystickInstanceID(joystick);
        if (instance_id < 0)
        {
            throw sdl_error();
        }

        return instance_id;
    }

    bool gamepad::is_connected() const
    {
        return SDL_GameControllerGetAttached(controller_.get());
    }

    bool gamepad::is_pressed(gamepad_button button) const
    {
        Uint8 state = SDL_GameControllerGetButton(controller_.get(), detail::convert_gamepad_button(button));
        return state == 1;
    }

    float gamepad::position(gamepad_axis axis) const
    {
        Sint16 position = SDL_GameControllerGetAxis(controller_.get(), detail::convert_gamepad_axis(axis));
        return detail::normalize_gamepad_axis(position);
    }
}
