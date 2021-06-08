#pragma once

#include <mio/point.hpp>
#include <string>
#include <memory>

struct SDL_Window;

namespace mio
{
    class window
    {
    public:
        window(const std::string& title, int width, int height);

        window(SDL_Window* handle);

        window(const window&) = delete;

        window(window&&) = default;

        window& operator=(const window&) = delete;

        window& operator=(window&&) = default;

        ~window();

        SDL_Window* native_handle() const;

        unsigned int id() const;

        void visible(bool enable);

        bool visible() const;

        void fullscreen(bool enable);

        bool fullscreen() const;

        void size(point<int> size);

        point<int> size() const;

    private:
        std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> handle_;
    };
}
