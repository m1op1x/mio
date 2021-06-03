#include <mio/font.hpp>

#include <mio/exception.hpp>
#include <SDL_surface.h>
#include <SDL_ttf.h>

namespace mio
{
    font::font(const std::string& filename, int size)
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

    TTF_Font* font::native_handle() const
    {
        return font_.get();
    }

    point<int> font::measure(const std::string& text) const
    {
        point<int> size;
        if (TTF_SizeText(font_.get(), text.c_str(), &size.x, &size.y))
        {
            throw ttf_error();
        }
        return size;
    }

    image font::render(const std::string& text, mio::color color) const
    {
        SDL_Color foreground
        {
            color.r,
            color.g,
            color.b,
            color.a
        };

        SDL_Surface* surface = TTF_RenderText_Blended(font_.get(), text.c_str(), foreground);
        if (surface == nullptr)
        {
            throw ttf_error();
        }

        return image(surface);
    }
}
