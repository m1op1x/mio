#include <mio/font.hpp>

#include <mio/exception.hpp>
#include <SDL_surface.h>
#include <SDL_ttf.h>

namespace mio
{
    font::font(const std::string& filename, unsigned int size)
        : font_(nullptr, nullptr)
    {
        font_ =
        {
            TTF_OpenFont(filename.c_str(), size),
            TTF_CloseFont
        };

        if (font_ == nullptr)
        {
            throw ttf_error();
        }
    }

    font::~font()
    {
    }

    rectangle<int> font::measure(const std::string& text) const
    {
        rectangle<int> bounds;
        if (TTF_SizeText(font_.get(), text.c_str(), &bounds.width, & bounds.height))
        {
            throw ttf_error();
        }
        return bounds;
    }

    image font::render(const std::string& text, mio::color color) const
    {
        SDL_Color sdl_color
        {
            color.r,
            color.g,
            color.b,
            color.a
        };

        std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface
        {
            TTF_RenderText_Blended(font_.get(), text.c_str(), sdl_color),
            SDL_FreeSurface
        };

        if (surface == nullptr)
        {
            throw ttf_error();
        }

        return image(surface.release());
    }

    TTF_Font* font::get() const
    {
        return font_.get();
    }
}
