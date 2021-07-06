#pragma once

#include <memory>

namespace mio
{
    template <typename Service>
    class locator
    {
    public:
        locator() = delete;

        template <typename Impl = Service, typename... Args>
        static Service& emplace(Args&&... args);

        static void instance(std::shared_ptr<Service> service);

        static std::shared_ptr<Service> instance();

        static Service& reference();

        static bool valid();

        static void reset();

    private:
        inline static std::shared_ptr<Service> service_ {};
    };
}

#include <mio/locator.inl>
