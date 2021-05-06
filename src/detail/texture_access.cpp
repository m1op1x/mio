#include <mio/detail/texture_access.hpp>

#include <mio/exception.hpp>

namespace mio::detail
{
    SDL_TextureAccess convert_texture_access(texture_access access)
    {
        switch (access)
        {
            case texture_access::static_:
            {
                return SDL_TEXTUREACCESS_STATIC;
            }
            case texture_access::dynamic:
            {
                return SDL_TEXTUREACCESS_STREAMING;
            }
            case texture_access::target:
            {
                return SDL_TEXTUREACCESS_TARGET;
            }
            default:
            {
                throw exception("Invalid texture access");
            }
        }
    }
}
