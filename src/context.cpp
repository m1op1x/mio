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

        for (int i = 0; i < SDL_NumJoysticks(); i++)
        {
            if (SDL_IsGameController(i))
            {
                if (SDL_GameControllerOpen(i) == nullptr)
                {
                    throw sdl_error();
                }
            }
        }

        if (int flags = IMG_INIT_JPG | IMG_INIT_PNG; (IMG_Init(flags) & flags) != flags)
        {
            throw img_error();
        }

        if (TTF_Init())
        {
            throw ttf_error();
        }

        if (int flags = MIX_INIT_MP3; (Mix_Init(flags) & flags) != flags)
        {
            throw mix_error();
        }
    }

    context::~context()
    {
        Mix_Quit();
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }
}
