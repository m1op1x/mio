#include <mio/event.hpp>

#include <mio/detail/gamepad_axis.hpp>
#include <mio/detail/gamepad_button.hpp>
#include <mio/detail/mouse_button.hpp>
#include <mio/detail/scancode.hpp>
#include <mio/exception.hpp>
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
                        return keyboard_event
                        {
                            detail::convert_scancode(event.key.keysym.scancode),
                            button_state::pressed
                        };
                    }
                    break;
                }
                case SDL_KEYUP:
                {
                    return keyboard_event
                    {
                        detail::convert_scancode(event.key.keysym.scancode),
                        button_state::released
                    };
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    return mouse_button_event
                    {
                        detail::convert_mouse_button(event.button.button),
                        button_state::pressed,
                        event.button.x,
                        event.button.y
                    };
                }
                case SDL_MOUSEBUTTONUP:
                {
                    return mouse_button_event
                    {
                        detail::convert_mouse_button(event.button.button),
                        button_state::released,
                        event.button.x,
                        event.button.y
                    };
                }
                case SDL_MOUSEMOTION:
                {
                    return mouse_motion_event
                    {
                        event.motion.xrel,
                        event.motion.yrel,
                        event.motion.x,
                        event.motion.y
                    };
                }
                case SDL_CONTROLLERDEVICEADDED:
                {
                    SDL_GameController* controller = SDL_GameControllerOpen(event.cdevice.which);
                    if (controller == nullptr)
                    {
                        throw sdl_error();
                    }

                    SDL_Joystick* joystick = SDL_GameControllerGetJoystick(controller);
                    if (joystick == nullptr)
                    {
                        throw sdl_error();
                    }

                    SDL_JoystickID instance_id = SDL_JoystickInstanceID(joystick);
                    if (instance_id < 0)
                    {
                        throw sdl_error();
                    }

                    return gamepad_device_event
                    {
                        instance_id,
                        device_state::connected
                    };
                }
                case SDL_CONTROLLERDEVICEREMOVED:
                {
                    SDL_GameController* controller = SDL_GameControllerFromInstanceID(event.cdevice.which);
                    if (controller == nullptr)
                    {
                        throw sdl_error();
                    }

                    SDL_GameControllerClose(controller);

                    return gamepad_device_event
                    {
                        event.cdevice.which,
                        device_state::disconnected
                    };
                }
                case SDL_CONTROLLERBUTTONDOWN:
                {
                    return gamepad_button_event
                    {
                        event.cbutton.which,
                        detail::convert_gamepad_button(static_cast<SDL_GameControllerButton>(event.cbutton.button)),
                        button_state::pressed
                    };
                }
                case SDL_CONTROLLERBUTTONUP:
                {
                    return gamepad_button_event
                    {
                        event.cbutton.which,
                        detail::convert_gamepad_button(static_cast<SDL_GameControllerButton>(event.cbutton.button)),
                        button_state::released
                    };
                }
                case SDL_CONTROLLERAXISMOTION:
                {
                    return gamepad_axis_event
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
                            return window_size_event
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
