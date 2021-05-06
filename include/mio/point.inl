namespace mio
{
    template <typename T>
    point<T>::point()
        : x(0)
        , y(0)
    {
    }

    template <typename T>
    point<T>::point(T x, T y)
        : x(x)
        , y(y)
    {
    }

    template <typename T>
    template <typename U>
    point<T>::point(point<U> other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
    {
    }

    template <typename T>
    point<T>& point<T>::operator+=(point<T> other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    template <typename T>
    point<T>& point<T>::operator-=(point<T> other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    template <typename T>
    point<T>& point<T>::operator*=(T other)
    {
        x *= other;
        y *= other;
        return *this;
    }

    template <typename T>
    point<T>& point<T>::operator/=(T other)
    {
        x /= other;
        y /= other;
        return *this;
    }

    template <typename T>
    bool operator==(point<T> left, point<T> right)
    {
        return (left.x == right.x) && (left.y == right.y);
    }

    template <typename T>
    bool operator!=(point<T> left, point<T> right)
    {
        return (left.x != right.x) || (left.y != right.y);
    }

    template <typename T>
    point<T> operator+(point<T> left, point<T> right)
    {
        return point<T>(left.x + right.x, left.y + right.y);
    }

    template <typename T>
    point<T> operator-(point<T> left, point<T> right)
    {
        return point<T>(left.x - right.x, left.y - right.y);
    }

    template <typename T>
    point<T> operator-(point<T> right)
    {
        return point<T>(-right.x, -right.y);
    }

    template <typename T>
    point<T> operator*(point<T> left, T right)
    {
        return point<T>(left.x * right, left.y * right);
    }

    template <typename T>
    point<T> operator*(T left, point<T> right)
    {
        return point<T>(left * right.x, left * right.y);
    }

    template <typename T>
    point<T> operator/(point<T> left, T right)
    {
        return point<T>(left.x / right, left.y / right);
    }
}
