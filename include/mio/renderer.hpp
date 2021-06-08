#pragma once

#include <mio/window.hpp>
#include <mio/rectangle.hpp>
#include <mio/circle.hpp>
#include <mio/point.hpp>
#include <mio/color.hpp>
#include <memory>

struct SDL_Renderer;

namespace mio
{
    class texture;

    class renderer
    {
    public:
        renderer(const window& window);

        renderer(SDL_Renderer* handle);

        renderer(const renderer&) = delete;

        renderer(renderer&&) = default;

        renderer& operator=(const renderer&) = delete;

        renderer& operator=(renderer&&) = default;

        ~renderer();

        SDL_Renderer* native_handle() const;

        void logical_size(point<int> size);

        point<int> logical_size() const;

        void viewport(rectangle<int> viewport);

        rectangle<int> viewport() const;

        void target(texture* target);

        void clear(color color);

        void draw_point(point<float> point, color color);

        void draw_line(point<float> begin, point<float> end, color color);

        void draw_circle(circle<int> circle, color color);

        void fill_circle(circle<int> circle, color color);

        void draw_rectangle(rectangle<float> rectangle, color color);

        void fill_rectangle(rectangle<float> rectangle, color color);

        void draw_texture(const texture& texture, point<float> position);

        void draw_texture(const texture& texture, point<float> position, point<float> origin, point<float> scale, float rotation);

        void draw_texture(const texture& texture, rectangle<float> destination);

        void draw_texture(const texture& texture, rectangle<int> source, point<float> position);

        void draw_texture(const texture& texture, rectangle<int> source, point<float> position, point<float> origin, point<float> scale, float rotation);

        void draw_texture(const texture& texture, rectangle<int> source, rectangle<float> destination);

        void present();

    private:
        std::unique_ptr<SDL_Renderer, void (*)(SDL_Renderer*)> handle_;
    };
}
