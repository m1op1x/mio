#include <mio/keyboard.hpp>

#include <mio/detail/scancode.hpp>
#include <SDL_keyboard.h>

namespace mio::keyboard
{
    bool pressed(scancode key)
    {
        const Uint8* state = SDL_GetKeyboardState(nullptr);
        return state[detail::convert_scancode(key)];
    }
}
