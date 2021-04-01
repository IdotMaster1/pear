#include <Window.hpp>
#include <log.hpp>

using namespace pear;

int get_refresh_rate(SDL_Window *window)
{
    int display_index = SDL_GetWindowDisplayIndex(window);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(display_index, 0, &mode);

    return mode.refresh_rate;
}

void Window::register_event(int event, void (*handler)())
{
    events.push_back(std::make_pair(event, handler));
}

void Window::register_method(std::string name, void (*handler)())
{
    methods.push_back(std::make_pair(name, handler));
}
void Window::handle_events()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    if (event.type == SDL_QUIT)
    {
        is_running = false;
    }

    if (events.size() >= 1)
    {
        for (int i = 0; i < events.size(); i++)
        {

            if (event.type == events[i].first)
            {
                events[i].second();
            }
        }
    }
}

Window::Window(std::string name, int w, int h)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        is_running = true;
    }

    else
    {
        log("Pear failed to initialize, error: %d", SDL_GetError());
    }

    width = w;
    height = h;

    window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Window::process()
{
    if (methods.size() >= 1)
    {
        for (int i = 0; i < methods.size(); i++)
        {

            if (methods[i].first == "process")
            {
                methods[i].second();
            }
        }
    }
}

void Window::show()
{
    int FPS = get_refresh_rate(window);
    int frame_delay = 1000 / FPS;
    int frame_time;
    uint32_t frame_start;

    while (is_running)
    {
        frame_start = SDL_GetTicks();

        // Functions here

        handle_events();
        process();

        SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);

        frame_time = SDL_GetTicks() - frame_start;

        if (frame_delay > frame_time)
        {
            SDL_Delay(frame_delay - frame_time);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Window::background_color(SDL_Color color)
{
    bg_color = color;
}
