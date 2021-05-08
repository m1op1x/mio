#pragma once

namespace mio::detail
{
    int to_joystick_index(int gamepad_index);

    int to_gamepad_index(int joystick_index);
}
