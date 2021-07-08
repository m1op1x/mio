#include <mio/texture.hpp>

#include <mio/detail/texture_access.hpp>
#include <mio/exception.hpp>
#include <mio/renderer.hpp>
#include <SDL_render.h>
#include <SDL_image.h>

namespace mio
{
    texture::texture(const renderer& renderer, int width, int height, texture_access access)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            SDL_CreateTexture(renderer.native_handle(), SDL_PIXELFORMAT_RGBA32, detail::convert_texture_access(access), width, height),
            SDL_DestroyTexture
        };

        if (handle_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(const renderer& renderer, const std::string& filename)
        : handle_(nullptr, nullptr)
    {
        std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface(
            IMG_Load(filename.c_str()),
            SDL_FreeSurface);

        if (surface == nullptr)
        {
            throw img_error();
        }

        handle_ =
        {
            SDL_CreateTextureFromSurface(renderer.native_handle(), surface.get()),
            SDL_DestroyTexture
        };

        if (handle_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(const renderer& renderer, const image& image)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            SDL_CreateTextureFromSurface(renderer.native_handle(), image.native_handle()),
            SDL_DestroyTexture
        };

        if (handle_ == nullptr)
        {
            throw sdl_error();
        }
    }

    texture::texture(SDL_Texture* handle)
        : handle_(handle, SDL_DestroyTexture)
    {
        if (handle_ == nullptr)
        {
            throw exception("Invalid texture");
        }
    }

    texture::~texture()
    {
    }

    SDL_Texture* texture::native_handle() const
    {
        return handle_.get();
    }

    void texture::set_color(color color)
    {
        if (SDL_SetTextureColorMod(handle_.get(), color.r, color.g, color.b))
        {
            throw sdl_error();
        }

        if (SDL_SetTextureAlphaMod(handle_.get(), color.a))
        {
            throw sdl_error();
        }
    }

    point<int> texture::size() const
    {
        point<int> size;
        SDL_QueryTexture(handle_.get(), nullptr, nullptr, &size.x, &size.y);
        return size;
    }
}
