#include <mio/mixer.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio::mixer
{
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
