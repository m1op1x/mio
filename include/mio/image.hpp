#pragma once

#include <mio/color.hpp>
#include <string>
#include <memory>

struct SDL_Surface;

namespace mio
{
    class image
    {
    public:
        image(unsigned int width, unsigned int height, color color);

        image(const std::string& filename);

        image(SDL_Surface* surface);

        image(const image&) = delete;

        image(image&&) = default;

        image& operator=(const image&) = delete;

        image& operator=(image&&) = default;

        ~image();

        SDL_Surface* native_handle() const;

        unsigned int width() const;

        unsigned int height() const;

    private:
        std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> surface_;
    };
}
