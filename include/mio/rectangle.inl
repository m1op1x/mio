namespace mio
{
    template <typename T>
    rectangle<T>::rectangle()
        : x(0)
        , y(0)
        , width(0)
        , height(0)
    {
    }

    template <typename T>
    rectangle<T>::rectangle(T x, T y, T width, T height)
        : x(x)
        , y(y)
        , width(width)
        , height(height)
    {
    }

    template <typename T>
    template <typename U>
    rectangle<T>::rectangle(rectangle<U> other)
        : x(static_cast<T>(other.x))
        , y(static_cast<T>(other.y))
        , width(static_cast<T>(other.width))
        , height(static_cast<T>(other.height))
    {
    }

    template <typename T>
    void rectangle<T>::position(point<T> position)
    {
        x = position.x;
        y = position.y;
    }

    template <typename T>
    point<T> rectangle<T>::position() const
    {
        return point<T>(x, y);
    }

    template <typename T>
    void rectangle<T>::center(point<T> center)
    {
        x = center.x - width / 2;
        y = center.y - height / 2;
    }

    template <typename T>
    point<T> rectangle<T>::center() const
    {
        return point<T>(x + width / 2, y + height / 2);
    }

    template <typename T>
    void rectangle<T>::left(T value)
    {
        x = value;
    }

    template <typename T>
    T rectangle<T>::left() const
    {
        return x;
    }

    template <typename T>
    void rectangle<T>::right(T value)
    {
        x = value - width;
    }

    template <typename T>
    T rectangle<T>::right() const
    {
        return x + width;
    }

    template <typename T>
    void rectangle<T>::top(T value)
    {
        y = value;
    }

    template <typename T>
    T rectangle<T>::top() const
    {
        return y;
    }

    template <typename T>
    void rectangle<T>::bottom(T value)
    {
        y = value - height;
    }

    template <typename T>
    T rectangle<T>::bottom() const
    {
        return y + height;
    }

    template <typename T>
    void rectangle<T>::size(point<T> size)
    {
        width = size.x;
        height = size.y;
    }

    template <typename T>
    point<T> rectangle<T>::size() const
    {
        return point<T>(width, height);
    }

    template <typename T>
    bool rectangle<T>::contains(point<T> point) const
    {
        return point.x > left()
            && point.x < right()
            && point.y > top()
            && point.y < bottom();
    }

    template <typename T>
    void rectangle<T>::move(point<T> delta)
    {
        x += delta.x;
        y += delta.y;
    }
}
