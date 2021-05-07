#pragma once

#include <mio/button_state.hpp>
#include <mio/device_state.hpp>
#include <mio/gamepad_axis.hpp>
#include <mio/gamepad_button.hpp>
#include <mio/mouse_button.hpp>
#include <mio/scancode.hpp>

namespace mio
{
    struct keyboard_event
    {
        scancode key;
        button_state state;
    };

    struct mouse_button_event
    {
        mouse_button button;
        button_state state;
        int x;
        int y;
    };

    struct mouse_motion_event
    {
        int delta_x;
        int delta_y;
        int x;
        int y;
    };

    struct gamepad_device_event
    {
        int gamepad_id;
        device_state state;
    };

    struct gamepad_button_event
    {
        int gamepad_id;
        gamepad_button button;
        button_state state;
    };

    struct gamepad_axis_event
    {
        int gamepad_id;
        gamepad_axis axis;
        float position;
    };

    struct window_size_event
    {
        unsigned int window_id;
        int width;
        int height;
    };

    struct window_close_event
    {
        unsigned int window_id;
    };

    struct quit_event
    {
    };
}
