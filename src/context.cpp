#include <mio/context.hpp>

#include <mio/exception.hpp>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace mio
{
    context::context()
    {
        if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS | SDL_INIT_GAMECONTROLLER))
        {
            throw sdl_error();
        }

        if (int flags = IMG_INIT_JPG | IMG_INIT_PNG; (IMG_Init(flags) & flags) != flags)
        {
            throw img_error();
        }

        if (TTF_Init())
        {
            throw ttf_error();
        }

        if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4096))
        {
            throw mix_error();
        }
    }

    context::~context()
    {
        Mix_CloseAudio();
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}
