#pragma once

#include <chrono>

namespace mio
{
    class clock
    {
    public:
        clock();

        clock& operator+=(float duration);

        clock& operator-=(float duration);

        float elapsed() const;

        float restart();

    private:
        std::chrono::steady_clock::time_point start_;
    };
}
