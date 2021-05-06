#include <mio/color.hpp>

namespace mio
{
    const color color::transparent(255, 255, 255, 0);
    const color color::white(255, 255, 255, 255);
    const color color::black(0, 0, 0, 255);
    const color color::red(255, 0, 0, 255);
    const color color::green(0, 255, 0, 255);
    const color color::blue(0, 0, 255, 255);
    const color color::yellow(255, 255, 0, 255);
    const color color::magenta(255, 0, 255, 255);
    const color color::cyan(0, 255, 255, 255);

    color::color()
        : r(255)
        , g(255)
        , b(255)
        , a(255)
    {
    }

    color::color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a)
        : r(r)
        , g(g)
        , b(b)
        , a(a)
    {
    }

    color::color(std::uint32_t packed)
        : r((packed >> 0x18) & 0xFF)
        , g((packed >> 0x10) & 0xFF)
        , b((packed >> 0x08) & 0xFF)
        , a((packed >> 0x00) & 0xFF)
    {
    }

    std::uint32_t color::packed() const
    {
        return (r << 0x18) | (g << 0x10) | (b << 0x08) | (a << 0x00);
    }
}
