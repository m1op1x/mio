#pragma once

#include <mio/gamepad_button.hpp>
#include <mio/gamepad_axis.hpp>
#include <memory>

typedef struct _SDL_GameController SDL_GameController;

namespace mio
{
    class gamepad
    {
    public:
        static int device_count();

        gamepad(int device_index);

        gamepad(SDL_GameController* handle);

        SDL_GameController* native_handle() const;

        int instance_id() const;

        bool connected() const;

        bool pressed(gamepad_button button) const;

        float position(gamepad_axis axis) const;

    private:
        std::shared_ptr<SDL_GameController> handle_;
    };
}
