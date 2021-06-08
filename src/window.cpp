#include <mio/window.hpp>

#include <mio/exception.hpp>
#include <SDL_video.h>

namespace mio
{
    window::window(const std::string& title, int width, int height)
        : handle_(nullptr, nullptr)
    {
        handle_ =
        {
            SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0),
            SDL_DestroyWindow
        };

        if (handle_ == nullptr)
        {
            throw sdl_error();
        }
    }

    window::window(SDL_Window* handle)
        : handle_(handle, SDL_DestroyWindow)
    {
        if (handle_ == nullptr)
        {
            throw exception("Invalid window");
        }
    }

    window::~window()
    {
    }

    SDL_Window* window::native_handle() const
    {
        return handle_.get();
    }

    unsigned int window::id() const
    {
        return SDL_GetWindowID(handle_.get());
    }

    bool window::visible() const
    {
        return SDL_GetWindowFlags(handle_.get()) & SDL_WINDOW_SHOWN;
    }

    void window::visible(bool enable)
    {
        if (enable)
        {
            SDL_ShowWindow(handle_.get());
        }
        else
        {
            SDL_HideWindow(handle_.get());
        }
    }

    bool window::fullscreen() const
    {
        return SDL_GetWindowFlags(handle_.get()) & SDL_WINDOW_FULLSCREEN;
    }

    void window::fullscreen(bool enable)
    {
        if (SDL_SetWindowFullscreen(handle_.get(), (enable) ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0))
        {
            throw sdl_error();
        }
    }

    void window::size(point<int> size)
    {
        SDL_SetWindowSize(handle_.get(), size.x, size.y);
    }

    point<int> window::size() const
    {
        point<int> size;
        SDL_GetWindowSize(handle_.get(), &size.x, &size.y);
        return size;
    }
}
