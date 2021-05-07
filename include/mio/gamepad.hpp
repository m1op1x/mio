#pragma once

#include <mio/gamepad_button.hpp>
#include <mio/gamepad_axis.hpp>
#include <optional>

typedef struct _SDL_GameController SDL_GameController;

namespace mio
{
    class gamepad
    {
    public:
        static std::optional<gamepad> from_index(unsigned int index);

        static std::optional<gamepad> from_id(unsigned int id);

        gamepad(SDL_GameController* controller);

        SDL_GameController* native_handle() const;

        unsigned int id() const;

        bool is_connected() const;

        bool is_pressed(gamepad_button button) const;

        float position(gamepad_axis axis) const;

    private:
        SDL_GameController* controller_;
    };
}
