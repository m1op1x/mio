namespace mio
{
    template <typename T>
    event::event(const T& data)
        : data_(data)
    {
    }

    template <typename T>
    bool event::holds() const
    {
        return std::holds_alternative<T>(data_);
    }

    template <typename T>
    const T& event::get() const
    {
        return std::get<T>(data_);
    }

    template <typename T>
    T& event::get()
    {
        return std::get<T>(data_);
    }

    template <typename T>
    const T* event::try_get() const
    {
        return std::get_if<T>(&data_);
    }

    template <typename T>
    T* event::try_get()
    {
        return std::get_if<T>(&data_);
    }
}
