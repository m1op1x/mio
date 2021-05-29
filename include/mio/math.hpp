#pragma once

#include <mio/point.hpp>

namespace mio
{
    point<float> polar(float length, float angle);

    float length_squared(point<float> vector);

    float length(point<float> vector);

    float angle(point<float> vector);

    point<float> normalize(point<float> vector);

    point<float> reflect(point<float> vector, point<float> normal);

    point<float> rotate(point<float> vector, float angle);

    float cross(point<float> a, point<float> b);

    float dot(point<float> a, point<float> b);

    float to_degrees(float radians);

    float to_radians(float degrees);
}
