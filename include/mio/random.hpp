#pragma once

#include <random>

namespace mio
{
    class random
    {
    public:
        random();

        random(unsigned int seed);

        unsigned int seed() const;

        template <typename T>
        T next(T max);

        template <typename T>
        T next(T min, T max);

    private:
        const unsigned int seed_;
        std::mt19937 engine_;
    };
}

#include <mio/random.inl>
