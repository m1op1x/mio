namespace mio
{
    template <typename T>
    circle<T>::circle()
        : x(0)
        , y(0)
        , radius(0)
    {
    }

    template <typename T>
    circle<T>::circle(T x, T y, T radius)
        : x(x)
        , y(y)
        , radius(radius)
    {
    }

    template <typename T>
    template <typename U>
    circle<T>::circle(circle<U> other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
        , radius(static_cast<T>(other.radius))
    {
    }

    template <typename T>
    void circle<T>::position(point<T> position)
    {
        x = position.x;
        y = position.y;
    }

    template <typename T>
    point<T> circle<T>::position() const
    {
        return point<T>(x, y);
    }

    template <typename T>
    bool circle<T>::contains(point<T> point) const
    {
        T dx = point.x - x;
        T dy = point.y - y;
        return (dx * dx + dy * dy) < radius * radius;
    }

    template <typename T>
    void circle<T>::move(point<T> delta)
    {
        x += delta.x;
        y += delta.y;
    }
}
