#pragma once

#include <mio/music.hpp>

namespace mio::mixer
{
    void play_music(const music& music);

    void pause_music();

    void resume_music();

    void stop_music();
}
