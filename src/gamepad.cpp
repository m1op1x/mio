#include <mio/gamepad.hpp>

#include <mio/detail/gamepad_axis.hpp>
#include <mio/detail/gamepad_button.hpp>
#include <mio/exception.hpp>
#include <SDL_gamecontroller.h>

namespace mio
{
    std::optional<gamepad> gamepad::from_index(unsigned int index)
    {
        if (SDL_GameController* controller = SDL_GameControllerFromPlayerIndex(index))
        {
            return controller;
        }
        return std::nullopt;
    }

    std::optional<gamepad> gamepad::from_id(unsigned int id)
    {
        if (SDL_GameController* controller = SDL_GameControllerFromInstanceID(id))
        {
            return controller;
        }
        return std::nullopt;
    }

    gamepad::gamepad(SDL_GameController* controller)
        : controller_(controller)
    {
        if (controller_ == nullptr)
        {
            throw exception("Invalid game controller");
        }
    }

    unsigned int gamepad::id() const
    {
        SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller_);
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
        return SDL_GameControllerGetAttached(controller_);
    }

    bool gamepad::is_pressed(gamepad_button button) const
    {
        Uint8 state = SDL_GameControllerGetButton(controller_, detail::convert_gamepad_button(button));
        return state == 1;
    }

    float gamepad::position(gamepad_axis axis) const
    {
        Sint16 position = SDL_GameControllerGetAxis(controller_, detail::convert_gamepad_axis(axis));
        return detail::normalize_gamepad_axis(position);
    }

    SDL_GameController* gamepad::get() const
    {
        return controller_;
    }
}
