#pragma once

#include <mio/image.hpp>
#include <mio/point.hpp>
#include <mio/color.hpp>
#include <string>
#include <memory>

typedef struct _TTF_Font TTF_Font;

namespace mio
{
    class font
    {
    public:
        font(const std::string& filename, int size);

        font(TTF_Font* handle);

        font(const font&) = delete;

        font(font&&) = default;

        font& operator=(const font&) = delete;

        font& operator=(font&&) = default;

        ~font();

        TTF_Font* native_handle() const;

        point<int> size_of(const std::string& text) const;

        image render(const std::string& text, mio::color color) const;

    private:
        std::unique_ptr<TTF_Font, void (*)(TTF_Font*)> handle_;
    };
}
