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

        void left(T value);

        T left() const;

        void right(T value);

        T right() const;

        void top(T value);

        T top() const;

        void bottom(T value);

        T bottom() const;

        bool contains(point<T> point) const;

        void move(point<T> delta);

        T x;
        T y;
        T radius;
    };
}

#include <mio/circle.inl>
