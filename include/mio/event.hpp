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
        bool holds() const;

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
            keyboard_event,
            mouse_button_event,
            mouse_motion_event,
            gamepad_device_event,
            gamepad_button_event,
            gamepad_axis_event,
            window_size_event,
            window_close_event,
            quit_event>;

        variant_type data_;
    };
}

#include <mio/event.inl>
