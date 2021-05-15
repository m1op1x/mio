#pragma once

#include <mio/music.hpp>
#include <mio/sound.hpp>

namespace mio::mixer
{
    void play_sound(const sound& sound, int channel);

    int play_sound(const sound& sound);

    void pause_sound(int channel);

    void resume_sound(int channel);

    void stop_sound(int channel);

    void play_music(const music& music);

    void pause_music();

    void resume_music();

    void stop_music();
}
