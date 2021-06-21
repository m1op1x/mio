#include <mio/sound.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio
{
    sound::sound(const std::string& filename)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            Mix_LoadWAV(filename.c_str()),
            Mix_FreeChunk
        };

        if (handle_ == nullptr)
        {
            throw mix_error();
        }
    }

    sound::sound(Mix_Chunk* handle)
        : handle_(handle, Mix_FreeChunk)
    {
        if (handle_ == nullptr)
        {
            throw exception("Invalid chunk");
        }
    }

    sound::~sound()
    {
    }

    Mix_Chunk* sound::native_handle() const
    {
        return handle_.get();
    }
}
