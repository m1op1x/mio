#pragma once

#include <mio/event_types.hpp>
#include <optional>
#include <variant>

namespace mio
{
    class event
    {
    public:
        static std::optional<event> poll();

        template <typename T>
        event(const T& data);

        template <typename T>
        bool is() const;

        template <typename T>
        const T& get() const;

        template <typename T>
        T& get();

        template <typename T>
        const T* try_get() const;

        template <typename T>
        T* try_get();

    private:
        using variant_type = std::variant<
            keyboard_press_event,
            keyboard_release_event,
            mouse_press_event,
            mouse_release_event,
            mouse_move_event,
            gamepad_connect_event,
            gamepad_disconnect_event,
            gamepad_press_event,
            gamepad_release_event,
            gamepad_move_event,
            window_resize_event,
            window_close_event,
            quit_event>;

        variant_type data_;
    };
}

#include <mio/event.inl>
