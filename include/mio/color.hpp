#pragma once

#include <cstdint>

namespace mio
{
    class color
    {
    public:
        static const color transparent;
        static const color white;
        static const color black;
        static const color red;
        static const color green;
        static const color blue;
        static const color yellow;
        static const color magenta;
        static const color cyan;

        color();

        color(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a = 255);

        explicit color(std::uint32_t packed);

        std::uint32_t packed() const;

        std::uint8_t r;
        std::uint8_t g;
        std::uint8_t b;
        std::uint8_t a;
    };
}
