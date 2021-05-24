namespace mio
{
    template <typename T>
    T random::next(T max)
    {
        return next(T {}, max);
    }

    template <typename T>
    T random::next(T min, T max)
    {
        if constexpr (std::is_floating_point_v<T>)
        {
            std::uniform_real_distribution dist(min, max);
            return dist(engine_);
        }
        else
        {
            std::uniform_int_distribution dist(min, max);
            return dist(engine_);
        }
    }
}
