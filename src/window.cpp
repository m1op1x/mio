#include <mio/window.hpp>

#include <mio/exception.hpp>
#include <SDL_video.h>

namespace mio
{
    window::window(const std::string& title, unsigned int width, unsigned int height)
        : window_(nullptr, nullptr)
        , active_(true)
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
        , active_(true)
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
        if (active_)
        {
            return SDL_GetWindowID(window_.get());
        }
        return 0;
    }

    bool window::is_open() const
    {
        return active_;
    }

    void window::close()
    {
        SDL_HideWindow(window_.get());
        active_ = false;
    }

    void window::resize(unsigned int width, unsigned int height)
    {
        if (active_)
        {
            SDL_SetWindowSize(window_.get(), width, height);
        }
    }

    unsigned int window::width() const
    {
        if (active_)
        {
            int width;
            SDL_GetWindowSize(window_.get(), &width, nullptr);
            return width;
        }
        return 0;
    }

    unsigned int window::height() const
    {
        if (active_)
        {
            int height;
            SDL_GetWindowSize(window_.get(), nullptr, &height);
            return height;
        }
        return 0;
    }
}
