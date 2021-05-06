#pragma once

namespace mio
{
    template <typename T>
    class circle
    {
    public:
        circle();

        circle(T x, T y, T radius);

        template <typename U>
        explicit circle(circle<U> other);

        void position(point<T> position);

        point<T> position() const;

        bool contains(point<T> point) const;

        void move(point<T> delta);

        T x;
        T y;
        T radius;
    };
}

#include <mio/circle.inl>
