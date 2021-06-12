#include <mio/exception.hpp>

#include <SDL_error.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

namespace mio
{
    exception::exception(std::string_view what)
        : what_(what)
    {
    }

    const char* exception::what() const noexcept
    {
        return what_.c_str();
    }

    sdl_error::sdl_error()
        : exception(SDL_GetError())
    {
    }

    img_error::img_error()
        : exception(IMG_GetError())
    {
    }

    ttf_error::ttf_error()
        : exception(TTF_GetError())
    {
    }

    mix_error::mix_error()
        : exception(Mix_GetError())
    {
    }
}
