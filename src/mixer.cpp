#include <mio/mixer.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio::mixer
{
    void play_sound(const sound& sound, int channel)
    {
        if (Mix_PlayChannel(channel, sound.native_handle(), 0) == -1)
        {
            throw mix_error();
        }
    }

    int play_sound(const sound& sound)
    {
        int channel = Mix_PlayChannel(-1, sound.native_handle(), 0);
        if (channel == -1)
        {
            throw mix_error();
        }
        return channel;
    }

    void pause_sound(int channel)
    {
        Mix_Pause(channel);
    }

    void resume_sound(int channel)
    {
        Mix_Resume(channel);
    }

    void stop_sound(int channel)
    {
        Mix_HaltChannel(channel);
    }

    void play_music(const music& music)
    {
        if (Mix_PlayMusic(music.native_handle(), 1))
        {
            throw mix_error();
        }
    }

    void pause_music()
    {
        Mix_PauseMusic();
    }

    void resume_music()
    {
        Mix_ResumeMusic();
    }

    void stop_music()
    {
        Mix_HaltMusic();
    }
}
