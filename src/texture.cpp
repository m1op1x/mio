#include <mio/texture.hpp>

#include <mio/detail/texture_access.hpp>
#include <mio/exception.hpp>
#include <mio/renderer.hpp>
#include <SDL_render.h>
#include <SDL_image.h>

namespace mio
{
    texture::texture(const renderer& renderer, int width, int height, texture_access access)
        : texture_(nullptr, nullptr)
    {
        texture_ =
        {
            SDL_CreateTexture(renderer.native_handle(), SDL_PIXELFORMAT_RGBA32, detail::convert_texture_access(access), width, height),
            SDL_DestroyTexture
        };

        if (texture_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(const renderer& renderer, const std::string& filename)
        : texture_(nullptr, nullptr)
    {
        std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface
        {
            IMG_Load(filename.c_str()),
            SDL_FreeSurface
        };

        if (surface == nullptr)
        {
            throw img_error();
        }

        texture_ =
        {
            SDL_CreateTextureFromSurface(renderer.native_handle(), surface.get()),
            SDL_DestroyTexture
        };

        if (texture_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(const renderer& renderer, const image& image)
        : texture_(nullptr, nullptr)
    {
        texture_ =
        {
            SDL_CreateTextureFromSurface(renderer.native_handle(), image.native_handle()),
            SDL_DestroyTexture
        };

        if (texture_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(SDL_Texture* texture)
        : texture_(texture, SDL_DestroyTexture)
    {
        if (texture_ == nullptr)
        {
            throw exception("Invalid texture");
        }
    }

    texture::~texture()
    {
    }

    SDL_Texture* texture::native_handle() const
    {
        return texture_.get();
    }

    void texture::set_color(color color)
    {
        if (SDL_SetTextureColorMod(texture_.get(), color.r, color.g, color.b))
        {
            throw sdl_error();
        }
        if (SDL_SetTextureAlphaMod(texture_.get(), color.a))
        {
            throw sdl_error();
        }
    }

    int texture::width() const
    {
        int width = 0;
        SDL_QueryTexture(texture_.get(), nullptr, nullptr, &width, nullptr);
        return width;
    }

    int texture::height() const
    {
        int height = 0;
        SDL_QueryTexture(texture_.get(), nullptr, nullptr, nullptr, &height);
        return height;
    }
}
