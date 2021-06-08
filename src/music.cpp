#include <mio/music.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio
{
    music::music(const std::string& filename)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            Mix_LoadMUS(filename.c_str()),
            Mix_FreeMusic
        };

        if (handle_ == nullptr)
        {
            throw mix_error();
        }
    }

    music::music(Mix_Music* handle)
        : handle_(handle, Mix_FreeMusic)
    {
        if (handle_ == nullptr)
        {
            throw exception("Invalid music");
        }
    }

    music::~music()
    {
    }

    Mix_Music* music::native_handle() const
    {
        return handle_.get();
    }
}
