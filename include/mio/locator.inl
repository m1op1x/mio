namespace mio
{
    template <typename Service>
    template <typename Impl, typename... Args>
    Service& locator<Service>::emplace(Args&&... args)
    {
        service_ = std::make_shared<Impl>(std::forward<Args>(args)...);
        return *service_;
    }

    template <typename Service>
    void locator<Service>::instance(std::shared_ptr<Service> service)
    {
        service_ = std::move(service);
    }

    template <typename Service>
    std::shared_ptr<Service> locator<Service>::instance()
    {
        return service_;
    }

    template <typename Service>
    Service& locator<Service>::reference()
    {
        return *service_;
    }

    template <typename Service>
    bool locator<Service>::valid()
    {
        return static_cast<bool>(service_);
    }

    template <typename Service>
    void locator<Service>::reset()
    {
        service_.reset();
    }
}
