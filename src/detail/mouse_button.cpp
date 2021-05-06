#include <mio/detail/mouse_button.hpp>

#include <mio/exception.hpp>
#include <SDL_mouse.h>

namespace mio::detail
{
    mouse_button convert_mouse_button(int button)
    {
        switch (button)
        {
            case SDL_BUTTON_LEFT:
            {
                return mouse_button::left;
            }
            case SDL_BUTTON_MIDDLE:
            {
                return mouse_button::middle;
            }
            case SDL_BUTTON_RIGHT:
            {
                return mouse_button::right;
            }
            case SDL_BUTTON_X1:
            {
                return mouse_button::x1;
            }
            case SDL_BUTTON_X2:
            {
                return mouse_button::x2;
            }
            default:
            {
                throw exception("Invalid mouse button");
            }
        }
    }

    int convert_mouse_button(mouse_button button)
    {
        switch (button)
        {
            case mouse_button::left:
            {
                return SDL_BUTTON_LEFT;
            }
            case mouse_button::middle:
            {
                return SDL_BUTTON_MIDDLE;
            }
            case mouse_button::right:
            {
                return SDL_BUTTON_RIGHT;
            }
            case mouse_button::x1:
            {
                return SDL_BUTTON_X1;
            }
            case mouse_button::x2:
            {
                return SDL_BUTTON_X2;
            }
            default:
            {
                throw exception("Invalid mouse button");
            }
        }
    }
}
