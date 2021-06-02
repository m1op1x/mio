#include <mio.hpp>

int main()
{
    mio::context context;

    mio::window window("title", 1280, 720);

    mio::renderer renderer(window);

    bool is_running = true;

    while (is_running)
    {
        while (auto event = mio::event::poll())
        {
            if (event->is<mio::quit_event>())
            {
                is_running = false;
            }
        }

        renderer.clear(mio::color::white);

        renderer.present();
    }
}
