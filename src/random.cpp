#include <mio/random.hpp>

namespace mio
{
    random::random()
        : seed_(std::random_device {}())
        , engine_(seed_)
    {
    }

    random::random(unsigned int seed)
        : seed_(seed)
        , engine_(seed)
    {
    }

    unsigned int random::seed() const
    {
        return seed_;
    }
}
