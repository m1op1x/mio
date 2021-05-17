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

    void window::resize(int width, int height)
    {
        SDL_SetWindowSize(window_.get(), width, height);
    }

    int window::width() const
    {
        int width;
        SDL_GetWindowSize(window_.get(), &width, nullptr);
        return width;
    }

    int window::height() const
    {
        int height;
        SDL_GetWindowSize(window_.get(), nullptr, &height);
        return height;
    }

    void window::show()
    {
        SDL_ShowWindow(window_.get());
    }

    void window::hide()
    {
        SDL_HideWindow(window_.get());
    }
}
