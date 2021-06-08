#pragma once

#include <string>
#include <memory>

typedef struct _Mix_Music Mix_Music;

namespace mio
{
    class music
    {
    public:
        music(const std::string& filename);

        music(Mix_Music* handle);

        music(const music&) = delete;

        music(music&&) = default;

        music& operator=(const music&) = delete;

        music& operator=(music&&) = default;

        ~music();

        Mix_Music* native_handle() const;

    private:
        std::unique_ptr<Mix_Music, void (*)(Mix_Music*)> handle_;
    };
}
