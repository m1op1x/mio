#include <mio/mouse.hpp>

#include <mio/detail/mouse_button.hpp>
#include <mio/exception.hpp>
#include <SDL_mouse.h>

namespace mio::mouse
{
    bool pressed(mouse_button button)
    {
        Uint32 state = SDL_GetMouseState(nullptr, nullptr);
        return state & SDL_BUTTON(detail::convert_mouse_button(button));
    }

    void position(point<int>)
    {
        throw exception("Not implemented");
    }

    point<int> position()
    {
        point<int> position;
        SDL_GetMouseState(&position.x, &position.y);
        return position;
    }
}
