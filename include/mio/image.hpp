#pragma once

#include <mio/point.hpp>
#include <mio/color.hpp>
#include <string>
#include <memory>

struct SDL_Surface;

namespace mio
{
    class image
    {
    public:
        image(int width, int height, color color);

        image(const std::string& filename);

        image(SDL_Surface* handle);

        image(const image&) = delete;

        image(image&&) = default;

        image& operator=(const image&) = delete;

        image& operator=(image&&) = default;

        ~image();

        SDL_Surface* native_handle() const;

        mio::point<int> size() const;

    private:
        std::unique_ptr<SDL_Surface, void (*)(SDL_Surface*)> handle_;
    };
}
