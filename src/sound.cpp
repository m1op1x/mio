#include <mio/sound.hpp>

#include <mio/exception.hpp>
#include <SDL_mixer.h>

namespace mio
{
    sound::sound(const std::string& filename)
        : chunk_(nullptr, nullptr)
    {
        chunk_ =
        {
            Mix_LoadWAV(filename.c_str()),
            Mix_FreeChunk
        };

        if (chunk_ == nullptr)
        {
            throw mix_error();
        }
    }

    sound::sound(Mix_Chunk* chunk)
        : chunk_(chunk, Mix_FreeChunk)
    {
        if (chunk_ == nullptr)
        {
            throw exception("Invalid chunk");
        }
    }

    sound::~sound()
    {
    }

    Mix_Chunk* sound::native_handle() const
    {
        return chunk_.get();
    }
}
