#pragma once

#include <mio/point.hpp>

namespace mio
{
    template <typename T>
    class rectangle
    {
    public:
        rectangle();

        rectangle(T x, T y, T width, T height);

        rectangle(point<T> position, point<T> size);

        template <typename U>
        explicit rectangle(rectangle<U> other);

        void position(point<T> position);

        point<T> position() const;

        void center(point<T> center);

        point<T> center() const;

        void left(T value);

        T left() const;

        void right(T value);

        T right() const;

        void top(T value);

        T top() const;

        void bottom(T value);

        T bottom() const;

        void size(point<T> size);

        point<T> size() const;

        bool contains(point<T> point) const;

        void move(point<T> delta);

        T x;
        T y;
        T width;
        T height;
    };
}

#include <mio/rectangle.inl>
