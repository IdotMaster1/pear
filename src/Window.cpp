#include <Window.hpp>
#include <log.hpp>
#include <map>
using namespace pear;

int get_refresh_rate(SDL_Window *window)
{
    int display_index = SDL_GetWindowDisplayIndex(window);

    SDL_DisplayMode mode;

    SDL_GetDisplayMode(display_index, 0, &mode);

    return mode.refresh_rate;
}

void Window::register_event(int event, std::function<void()> handler)
{
    events.push_back(std::make_pair(event, handler));
}

int get_keycode_from_string(std::string code)
{
    std::map<std::string, int> keycodes;

    keycodes["arrow_up"] = SDLK_UP;
    keycodes["arrow_down"] = SDLK_DOWN;
    keycodes["arrow_left"] = SDLK_LEFT;
    keycodes["arrow_right"] = SDLK_RIGHT;
    keycodes["a"] = SDLK_a;
    keycodes["b"] = SDLK_b;
    keycodes["c"] = SDLK_c;
    keycodes["d"] = SDLK_d;
    keycodes["e"] = SDLK_e;
    keycodes["f"] = SDLK_f;
    keycodes["g"] = SDLK_g;
    keycodes["h"] = SDLK_h;
    keycodes["j"] = SDLK_j;
    keycodes["k"] = SDLK_k;
    keycodes["l"] = SDLK_l;
    keycodes["m"] = SDLK_m;
    keycodes["n"] = SDLK_n;
    keycodes["o"] = SDLK_o;
    keycodes["p"] = SDLK_p;
    keycodes["q"] = SDLK_q;
    keycodes["r"] = SDLK_r;
    keycodes["s"] = SDLK_s;
    keycodes["t"] = SDLK_t;
    keycodes["u"] = SDLK_u;
    keycodes["v"] = SDLK_v;
    keycodes["w"] = SDLK_w;
    keycodes["x"] = SDLK_x;
    keycodes["y"] = SDLK_y;
    keycodes["z"] = SDLK_z;


    return keycodes.find(code)->second;
}

void Window::register_event(std::string code, std::function<void()> handler)
{
    events.push_back(std::make_pair(get_keycode_from_string(code), handler));
}

void Window::register_method(std::string name, std::function<void()> handler)
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

            auto it = std::find_if(events.begin(), events.end(), [&event](const std::pair<int, std::function<void()>> &element) { return element.first == event.type; });

            if (it != events.end())
            {
                events[it - events.begin()].second();
            }
        }

        if (event.type == SDL_KEYDOWN)
        {

            auto it = std::find_if(events.begin(), events.end(), [&event](const std::pair<int, std::function<void()>> &element) { return element.first == event.key.keysym.sym; });

            if (it != events.end())
            {
                events[it - events.begin()].second();
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

void Window::draw(Image image, double rotation)
{
    SDL_RenderCopyEx(renderer, image.texture, &image.source, &image.destination, rotation, NULL, SDL_FLIP_NONE);
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

        SDL_SetRenderDrawColor(renderer, bg_color.r, bg_color.g, bg_color.b, bg_color.a);
        SDL_RenderClear(renderer);
        process();
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
