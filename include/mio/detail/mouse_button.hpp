#pragma once

#include <mio/mouse_button.hpp>

namespace mio::detail
{
    mouse_button convert_mouse_button(int button);

    int convert_mouse_button(mouse_button button);
}
