#include <mio/window.hpp>

#include <mio/exception.hpp>
#include <SDL_video.h>

namespace mio
{
    window::window(const std::string& title, int width, int height)
        : window_(nullptr, nullptr)
    {
        window_ =
        {
            SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0),
            SDL_DestroyWindow
        };

        if (window_ == nullptr)
        {
            throw sdl_error();
        }
    }

    window::window(SDL_Window* window)
        : window_(window, SDL_DestroyWindow)
    {
        if (window_ == nullptr)
        {
            throw exception("Invalid window");
        }
    }

    window::~window()
    {
    }

    SDL_Window* window::native_handle() const
    {
        return window_.get();
    }

    unsigned int window::id() const
    {
        return SDL_GetWindowID(window_.get());
    }

    bool window::visible() const
    {
        return SDL_GetWindowFlags(window_.get()) & SDL_WINDOW_SHOWN;
    }

    void window::visible(bool enable)
    {
        if (enable)
        {
            SDL_ShowWindow(window_.get());
        }
        else
        {
            SDL_HideWindow(window_.get());
        }
    }

    bool window::fullscreen() const
    {
        return SDL_GetWindowFlags(window_.get()) & SDL_WINDOW_FULLSCREEN;
    }

    void window::fullscreen(bool enable)
    {
        if (SDL_SetWindowFullscreen(window_.get(), (enable) ? SDL_WINDOW_FULLSCREEN_DESKTOP : 0))
        {
            throw sdl_error();
        }
    }

    void window::size(point<int> size)
    {
        SDL_SetWindowSize(window_.get(), size.x, size.y);
    }

    point<int> window::size() const
    {
        point<int> size;
        SDL_GetWindowSize(window_.get(), &size.x, &size.y);
        return size;
    }
}
