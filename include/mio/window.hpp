#pragma once

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

        bool is_open() const;

        void close();

        void resize(int width, int height);

        int width() const;

        int height() const;

    private:
        std::unique_ptr<SDL_Window, void (*)(SDL_Window*)> window_;
        bool active_;
    };
}
