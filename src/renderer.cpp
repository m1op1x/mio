#include <mio/renderer.hpp>

#include <mio/exception.hpp>
#include <mio/texture.hpp>
#include <SDL_render.h>

namespace mio
{
    renderer::renderer(const window& window)
        : renderer_(nullptr, nullptr)
    {
        renderer_ =
        {
            SDL_CreateRenderer(window.native_handle(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE | SDL_RENDERER_PRESENTVSYNC),
            SDL_DestroyRenderer
        };

        if (renderer_ == nullptr)
        {
            throw sdl_error();
        }
    }

    renderer::renderer(SDL_Renderer* renderer)
        : renderer_(renderer, SDL_DestroyRenderer)
    {
        if (renderer_ == nullptr)
        {
            throw exception("Invalid renderer");
        }
    }

    renderer::~renderer()
    {
    }

    SDL_Renderer* renderer::native_handle() const
    {
        return renderer_.get();
    }

    void renderer::logical_size(point<int> size)
    {
        if (SDL_RenderSetLogicalSize(renderer_.get(), size.x, size.y))
        {
            throw sdl_error();
        }
    }

    point<int> renderer::logical_size() const
    {
        point<int> size;
        SDL_RenderGetLogicalSize(renderer_.get(), &size.x, &size.y);
        return size;
    }

     void renderer::viewport(rectangle<int> viewport)
    {
        SDL_Rect rect
        {
            viewport.x,
            viewport.y,
            viewport.width,
            viewport.height
        };

        if (SDL_RenderSetViewport(renderer_.get(), &rect))
        {
            throw sdl_error();
        }
    }

    rectangle<int> renderer::viewport() const
    {
        SDL_Rect rect;
        SDL_RenderGetViewport(renderer_.get(), &rect);

        return rectangle
        {
            rect.x,
            rect.y,
            rect.w,
            rect.h
        };
    }

    void renderer::target(texture* target)
    {
        if (SDL_SetRenderTarget(renderer_.get(), (target) ? target->native_handle() : nullptr))
        {
            throw sdl_error();
        }
    }

    void renderer::clear(color color)
    {
        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        if (SDL_RenderClear(renderer_.get()))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_point(point<float> point, color color)
    {
        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        if (SDL_RenderDrawPointF(renderer_.get(), point.x, point.y))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_line(point<float> begin, point<float> end, color color)
    {
        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        if (SDL_RenderDrawLineF(renderer_.get(), begin.x, begin.y, end.x, end.y))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_circle(circle<int> circle, color color)
    {
        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        // Midpoint circle drawing algorithm.

        int decision = 1 - circle.radius;
        int offset_y = circle.radius;
        int offset_x = 0;

        while (offset_x <= offset_y)
        {
            int errors = 0;

            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x + offset_x, circle.y + offset_y);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x + offset_y, circle.y + offset_x);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x - offset_x, circle.y + offset_y);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x - offset_y, circle.y + offset_x);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x + offset_x, circle.y - offset_y);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x + offset_y, circle.y - offset_x);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x - offset_x, circle.y - offset_y);
            errors |= SDL_RenderDrawPoint(renderer_.get(), circle.x - offset_y, circle.y - offset_x);

            if (errors != 0)
            {
                throw sdl_error();
            }

            if (decision < 0)
            {
                offset_x++;
                decision += 2 * offset_x + 1;
            }
            else
            {
                offset_x++;
                offset_y--;
                decision += 2 * (offset_x - offset_y) + 1;
            }
        }
    }

    void renderer::fill_circle(circle<int> circle, color color)
    {
        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        // Midpoint circle drawing algorithm.

        int decision = 1 - circle.radius;
        int offset_y = circle.radius;
        int offset_x = 0;

        while (offset_x <= offset_y)
        {
            int errors = 0;

            errors |= SDL_RenderDrawLine(renderer_.get(), circle.x - offset_x, circle.y + offset_y, circle.x + offset_x, circle.y + offset_y);
            errors |= SDL_RenderDrawLine(renderer_.get(), circle.x - offset_y, circle.y + offset_x, circle.x + offset_y, circle.y + offset_x);
            errors |= SDL_RenderDrawLine(renderer_.get(), circle.x - offset_x, circle.y - offset_y, circle.x + offset_x, circle.y - offset_y);
            errors |= SDL_RenderDrawLine(renderer_.get(), circle.x - offset_y, circle.y - offset_x, circle.x + offset_y, circle.y - offset_x);

            if (errors != 0)
            {
                throw sdl_error();
            }

            if (decision < 0)
            {
                offset_x++;
                decision += 2 * offset_x + 1;
            }
            else
            {
                offset_x++;
                offset_y--;
                decision += 2 * (offset_x - offset_y) + 1;
            }
        }
    }

    void renderer::draw_rectangle(rectangle<float> rectangle, color color)
    {
        SDL_FRect dstrect
        {
            rectangle.x,
            rectangle.y,
            rectangle.width,
            rectangle.height
        };

        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        if (SDL_RenderDrawRectF(renderer_.get(), &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::fill_rectangle(rectangle<float> rectangle, color color)
    {
        SDL_FRect dstrect
        {
            rectangle.x,
            rectangle.y,
            rectangle.width,
            rectangle.height
        };

        if (SDL_SetRenderDrawColor(renderer_.get(), color.r, color.g, color.b, color.a))
        {
            throw sdl_error();
        }

        if (SDL_RenderFillRectF(renderer_.get(), &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, point<float> position)
    {
        auto [width, height] = texture.size();

        SDL_FRect dstrect
        {
            position.x,
            position.y,
            static_cast<float>(width),
            static_cast<float>(height)
        };

        if (SDL_RenderCopyF(renderer_.get(), texture.native_handle(), nullptr, &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, point<float> position, point<float> origin, point<float> scale, float rotation)
    {
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        if (scale.x < 0)
        {
            flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_HORIZONTAL);
            scale.x *= -1;
        }

        if (scale.y < 0)
        {
            flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_VERTICAL);
            scale.y *= -1;
        }

        auto [width, height] = texture.size();

        SDL_FRect dstrect
        {
            position.x - scale.x * origin.x,
            position.y - scale.y * origin.y,
            scale.x * static_cast<float>(width),
            scale.y * static_cast<float>(height)
        };

        SDL_FPoint center
        {
            scale.x * origin.x,
            scale.y * origin.y
        };

        if (SDL_RenderCopyExF(renderer_.get(), texture.native_handle(), nullptr, &dstrect, rotation, &center, flip))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, rectangle<float> destination)
    {
        SDL_FRect dstrect
        {
            destination.x,
            destination.y,
            destination.width,
            destination.height
        };

        if (SDL_RenderCopyF(renderer_.get(), texture.native_handle(), nullptr, &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, rectangle<int> source, point<float> position)
    {
        SDL_Rect srcrect
        {
            source.x,
            source.y,
            source.width,
            source.height
        };

        SDL_FRect dstrect
        {
            position.x,
            position.y,
            static_cast<float>(source.width),
            static_cast<float>(source.height)
        };

        if (SDL_RenderCopyF(renderer_.get(), texture.native_handle(), &srcrect, &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, rectangle<int> source, point<float> position, point<float> origin, point<float> scale, float rotation)
    {
        SDL_RendererFlip flip = SDL_FLIP_NONE;

        if (scale.x < 0)
        {
            flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_HORIZONTAL);
            scale.x *= -1;
        }

        if (scale.y < 0)
        {
            flip = static_cast<SDL_RendererFlip>(flip | SDL_FLIP_VERTICAL);
            scale.y *= -1;
        }

        SDL_Rect srcrect
        {
            source.x,
            source.y,
            source.width,
            source.height
        };

        SDL_FRect dstrect
        {
            position.x - scale.x * origin.x,
            position.y - scale.y * origin.y,
            scale.x * static_cast<float>(source.width),
            scale.y * static_cast<float>(source.height)
        };

        SDL_FPoint center
        {
            scale.x * origin.x,
            scale.y * origin.y
        };

        if (SDL_RenderCopyExF(renderer_.get(), texture.native_handle(), &srcrect, &dstrect, rotation, &center, flip))
        {
            throw sdl_error();
        }
    }

    void renderer::draw_texture(const texture& texture, rectangle<int> source, rectangle<float> destination)
    {
        SDL_Rect srcrect
        {
            source.x,
            source.y,
            source.width,
            source.height
        };

        SDL_FRect dstrect
        {
            destination.x,
            destination.y,
            destination.width,
            destination.height
        };

        if (SDL_RenderCopyF(renderer_.get(), texture.native_handle(), &srcrect, &dstrect))
        {
            throw sdl_error();
        }
    }

    void renderer::present()
    {
        SDL_RenderPresent(renderer_.get());
    }
}
