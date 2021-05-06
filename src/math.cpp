#include <mio/math.hpp>

#include <mio/exception.hpp>
#include <numbers>
#include <cmath>

static constexpr float pi = std::numbers::pi_v<float>;

namespace mio
{
    point<float> polar(float length, float angle)
    {
        float radians = to_radians(angle);
        float x = length * std::cos(radians);
        float y = length * std::sin(radians);
        return point<float>(x, y);
    }

    float length_squared(point<float> vector)
    {
        return vector.x * vector.x + vector.y * vector.y;
    }

    float length(point<float> vector)
    {
        return std::sqrt(length_squared(vector));
    }

    float angle(point<float> vector)
    {
        float radians = std::atan2(vector.y, vector.x);
        return to_degrees(radians);
    }

    point<float> normalize(point<float> vector)
    {
        return vector / length(vector);
    }

    point<float> reflect(point<float> vector, point<float> normal)
    {
        return vector - 2.0f * normal * dot(vector, normal);
    }

    point<float> rotate(point<float> vector, float angle)
    {
        throw exception("Not implemented");
    }

    point<float> clamp(point<float> vector, float length)
    {
        throw exception("Not implemented");
    }

    float cross(point<float> a, point<float> b)
    {
        return a.x * b.y - a.y * b.x;
    }

    float dot(point<float> a, point<float> b)
    {
        return a.x * b.x + a.y * b.y;
    }

    float to_degrees(float radians)
    {
        return (radians * 180.0f) / pi;
    }

    float to_radians(float degrees)
    {
        return (degrees * pi) / 180.0f;
    }
}
