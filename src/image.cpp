#include <mio/image.hpp>

#include <mio/exception.hpp>
#include <SDL_surface.h>
#include <SDL_image.h>

namespace mio
{
    image::image(int width, int height, color color)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            SDL_CreateRGBSurfaceWithFormat(0, width, height, 32, SDL_PIXELFORMAT_RGBA32),
            SDL_FreeSurface
        };

        if (handle_ == nullptr)
        {
            throw sdl_error();
        }

        auto pixels = static_cast<std::uint8_t*>(handle_->pixels);
        for (int i = 0; i < width * height; i++)
        {
            pixels[i * 4 + 0] = color.r;
            pixels[i * 4 + 1] = color.g;
            pixels[i * 4 + 2] = color.b;
            pixels[i * 4 + 3] = color.a;
        }
    }

    image::image(const std::string& filename)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            IMG_Load(filename.c_str()),
            SDL_FreeSurface
        };

        if (handle_ == nullptr)
        {
            throw img_error();
        }
    }

    image::image(SDL_Surface* handle)
        : handle_(handle, SDL_FreeSurface)
    {
        if (handle_ == nullptr)
        {
            throw exception("Invalid surface");
        }
    }

    image::~image()
    {
    }

    SDL_Surface* image::native_handle() const
    {
        return handle_.get();
    }

    mio::point<int> image::size() const
    {
        return point(handle_->w, handle_->h);
    }
}
