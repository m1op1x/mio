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

        window(SDL_Window* window);

        window(const window&) = delete;

        window(window&&) = default;

        window& operator=(const window&) = delete;

        window& operator=(window&&) = default;

        ~window();

        SDL_Window* native_handle() const;

        unsigned int id() const;

        void size(point<int> size);

        point<int> size() const;

        void show();

        void hide();

    private:
        std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> window_;
    };
}
