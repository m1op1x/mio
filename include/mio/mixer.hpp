#pragma once

#include <mio/music.hpp>
#include <mio/sound.hpp>

namespace mio::mixer
{
    void play_channel(const sound& sound, int channel);

    int play_channel(const sound& sound);

    void pause_channel(int channel);

    void resume_channel(int channel);

    void stop_channel(int channel);

    void channel_volume(int channel, float volume);

    float channel_volume(int channel);

    void play_stream(const music& music);

    void pause_stream();

    void resume_stream();

    void stop_stream();

    void stream_volume(float volume);

    float stream_volume();
}
