#pragma once

#include <mio/texture_access.hpp>
#include <mio/image.hpp>
#include <mio/color.hpp>
#include <string>
#include <memory>

struct SDL_Texture;

namespace mio
{
    class renderer;

    class texture
    {
    public:
        texture(const renderer& renderer, unsigned int width, unsigned int height, texture_access access);

        texture(const renderer& renderer, const std::string& filename);

        texture(const renderer& renderer, const image& image);

        texture(SDL_Texture* texture);

        texture(const texture&) = delete;

        texture(texture&&) = default;

        texture& operator=(const texture&) = delete;

        texture& operator=(texture&&) = default;

        ~texture();

        void set_color(color color);

        unsigned int width() const;

        unsigned int height() const;

        SDL_Texture* get() const;

    private:
        std::unique_ptr<SDL_Texture, void (*)(SDL_Texture*)> texture_;
    };
}
