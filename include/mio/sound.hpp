#pragma once

#include <string>
#include <memory>

struct Mix_Chunk;

namespace mio
{
    class sound
    {
    public:
        sound(const std::string& filename);

        sound(Mix_Chunk* chunk);

        sound(const sound&) = delete;

        sound(sound&&) = default;

        sound& operator=(const sound&) = delete;

        sound& operator=(sound&&) = default;

        ~sound();

        Mix_Chunk* native_handle() const;

    private:
        std::unique_ptr<Mix_Chunk, void (*)(Mix_Chunk*)> chunk_;
    };
}
