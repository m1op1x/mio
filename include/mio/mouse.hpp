#pragma once

#include <mio/mouse_button.hpp>
#include <mio/point.hpp>

namespace mio::mouse
{
    bool pressed(mouse_button button);

    void position(point<int> position);

    point<int> position();
}
