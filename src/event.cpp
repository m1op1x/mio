#include <mio/event.hpp>

#include <mio/detail/gamepad_button.hpp>
#include <mio/detail/gamepad_axis.hpp>
#include <mio/detail/gamepad.hpp>
#include <mio/detail/mouse_button.hpp>
#include <mio/detail/scancode.hpp>
#include <SDL_events.h>

namespace mio
{
    std::optional<event> event::poll()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                {
                    if (event.key.repeat == 0)
                    {
                        return keyboard_press_event
                        {
                            detail::convert_scancode(event.key.keysym.scancode)
                        };
                    }
                    break;
                }
                case SDL_KEYUP:
                {
                    return keyboard_release_event
                    {
                        detail::convert_scancode(event.key.keysym.scancode)
                    };
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    return mouse_press_event
                    {
                        detail::convert_mouse_button(event.button.button),
                        event.button.x,
                        event.button.y
                    };
                }
                case SDL_MOUSEBUTTONUP:
                {
                    return mouse_release_event
                    {
                        detail::convert_mouse_button(event.button.button),
                        event.button.x,
                        event.button.y
                    };
                }
                case SDL_MOUSEMOTION:
                {
                    return mouse_move_event
                    {
                        event.motion.xrel,
                        event.motion.yrel,
                        event.motion.x,
                        event.motion.y
                    };
                }
                case SDL_CONTROLLERDEVICEADDED:
                {
                    return gamepad_connect_event
                    {
                        detail::to_gamepad_index(event.cdevice.which)
                    };
                }
                case SDL_CONTROLLERDEVICEREMOVED:
                {
                    return gamepad_disconnect_event
                    {
                        event.cdevice.which
                    };
                }
                case SDL_CONTROLLERBUTTONDOWN:
                {
                    return gamepad_press_event
                    {
                        event.cbutton.which,
                        detail::convert_gamepad_button(static_cast<SDL_GameControllerButton>(event.cbutton.button))
                    };
                }
                case SDL_CONTROLLERBUTTONUP:
                {
                    return gamepad_release_event
                    {
                        event.cbutton.which,
                        detail::convert_gamepad_button(static_cast<SDL_GameControllerButton>(event.cbutton.button))
                    };
                }
                case SDL_CONTROLLERAXISMOTION:
                {
                    return gamepad_move_event
                    {
                        event.caxis.which,
                        detail::convert_gamepad_axis(static_cast<SDL_GameControllerAxis>(event.caxis.axis)),
                        detail::normalize_gamepad_axis(event.caxis.value)
                    };
                }
                case SDL_WINDOWEVENT:
                {
                    switch (event.window.event)
                    {
                        case SDL_WINDOWEVENT_RESIZED:
                        {
                            return window_resize_event
                            {
                                event.window.windowID,
                                event.window.data1,
                                event.window.data2
                            };
                        }
                        case SDL_WINDOWEVENT_CLOSE:
                        {
                            return window_close_event
                            {
                                event.window.windowID
                            };
                        }
                    }
                    break;
                }
                case SDL_QUIT:
                {
                    return quit_event {};
                }
            }
        }

        return std::nullopt;
    }
}
