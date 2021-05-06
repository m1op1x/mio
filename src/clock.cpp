#include <mio/clock.hpp>

namespace mio
{
    clock::clock()
        : start_(std::chrono::steady_clock::now())
    {
    }

    clock& clock::operator+=(float duration)
    {
        start_ -= std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<float>(duration));
        return *this;
    }

    clock& clock::operator-=(float duration)
    {
        start_ += std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::duration<float>(duration));
        return *this;
    }

    float clock::elapsed() const
    {
        auto runtime = std::chrono::steady_clock::now() - start_;
        return std::chrono::duration<float>(runtime).count();
    }

    float clock::restart()
    {
        float runtime = elapsed();
        start_ = std::chrono::steady_clock::now();
        return runtime;
    }
}
