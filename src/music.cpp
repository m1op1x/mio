#include <mio/music.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio
{
    music::music(const std::string& filename)
        : music_(nullptr, nullptr)
    {
        music_ =
        {
            Mix_LoadMUS(filename.c_str()),
            Mix_FreeMusic
        };

        if (music_ == nullptr)
        {
            throw mix_error();
        }
    }

    music::music(Mix_Music* music)
        : music_(music, Mix_FreeMusic)
    {
        if (music_ == nullptr)
        {
            throw exception("Invalid music");
        }
    }

    music::~music()
    {
    }

    Mix_Music* music::native_handle() const
    {
        return music_.get();
    }
}
