#include <mio/mixer.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>
#include <algorithm>

namespace mio::mixer
{
    void play_channel(const sound& sound, int channel)
    {
        if (Mix_PlayChannel(channel, sound.native_handle(), 0) == -1)
        {
            throw mix_error();
        }
    }

    int play_channel(const sound& sound)
    {
        int channel = Mix_PlayChannel(-1, sound.native_handle(), 0);
        if (channel == -1)
        {
            throw mix_error();
        }
        return channel;
    }

    void pause_channel(int channel)
    {
        Mix_Pause(channel);
    }

    void resume_channel(int channel)
    {
        Mix_Resume(channel);
    }

    void stop_channel(int channel)
    {
        Mix_HaltChannel(channel);
    }

    void channel_volume(int channel, float volume)
    {
        volume = std::clamp(volume, 0.0f, 1.0f) * MIX_MAX_VOLUME;
        Mix_Volume(channel, static_cast<int>(volume));
    }

    float channel_volume(int channel)
    {
        int volume = Mix_Volume(channel, -1);
        return static_cast<float>(volume) / MIX_MAX_VOLUME;
    }

    void play_stream(const music& music)
    {
        if (Mix_PlayMusic(music.native_handle(), 1))
        {
            throw mix_error();
        }
    }

    void pause_stream()
    {
        Mix_PauseMusic();
    }

    void resume_stream()
    {
        Mix_ResumeMusic();
    }

    void stop_stream()
    {
        Mix_HaltMusic();
    }

    void stream_volume(float volume)
    {
        volume = std::clamp(volume, 0.0f, 1.0f) * MIX_MAX_VOLUME;
        Mix_VolumeMusic(static_cast<int>(volume));
    }

    float stream_volume()
    {
        int volume = Mix_VolumeMusic(-1);
        return static_cast<float>(volume) / MIX_MAX_VOLUME;
    }
}
