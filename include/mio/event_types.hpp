#pragma once

#include <mio/gamepad_axis.hpp>
#include <mio/gamepad_button.hpp>
#include <mio/mouse_button.hpp>
#include <mio/scancode.hpp>

namespace mio
{
    struct keyboard_press_event
    {
        scancode key;
    };

    struct keyboard_release_event
    {
        scancode key;
    };

    struct mouse_press_event
    {
        mouse_button button;
        int x;
        int y;
    };

    struct mouse_release_event
    {
        mouse_button button;
        int x;
        int y;
    };

    struct mouse_move_event
    {
        int delta_x;
        int delta_y;
        int x;
        int y;
    };

    struct gamepad_connect_event
    {
        int device_index;
    };

    struct gamepad_disconnect_event
    {
        int instance_id;
    };

    struct gamepad_press_event
    {
        int instance_id;
        gamepad_button button;
    };

    struct gamepad_release_event
    {
        int instance_id;
        gamepad_button button;
    };

    struct gamepad_move_event
    {
        int instance_id;
        gamepad_axis axis;
        float position;
    };

    struct window_resize_event
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
