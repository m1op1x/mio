#pragma once

namespace mio
{
    template <typename T>
    class point
    {
    public:
        static const point<T> unit_x;
        static const point<T> unit_y;
        static const point<T> zero;

        point();

        point(T x, T y);

        template <typename U>
        explicit point(point<U> other);

        point<T>& operator+=(point<T> other);

        point<T>& operator-=(point<T> other);

        point<T>& operator*=(T other);

        point<T>& operator/=(T other);

        T x;
        T y;
    };

    template <typename T>
    bool operator==(point<T> left, point<T> right);

    template <typename T>
    bool operator!=(point<T> left, point<T> right);

    template <typename T>
    point<T> operator+(point<T> left, point<T> right);

    template <typename T>
    point<T> operator-(point<T> left, point<T> right);

    template <typename T>
    point<T> operator-(point<T> right);

    template <typename T>
    point<T> operator*(point<T> left, T right);

    template <typename T>
    point<T> operator*(T left, point<T> right);

    template <typename T>
    point<T> operator/(point<T> left, T right);
}

#include <mio/point.inl>
