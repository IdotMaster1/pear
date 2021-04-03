#ifndef PEAR_WINDOW_HPP
#define PEAR_WINDOW_HPP
#include <SDL2/SDL.h>
#include <functional>
#include <string>
#include <vector>
namespace pear
{

class Window
{
public:
    SDL_Window *window;
    SDL_Renderer *renderer;

    Window(std::string name, int w, int h);
    std::string name;

    std::vector <std::pair<std::string, std::function<void()>>> methods;

    void register_event(int event, std::function<void()> handler);
    void register_method(std::string name, std::function<void()> handler);
    void show();
    void background_color(SDL_Color color);

private:
    int width, height;

    bool is_running;
    std::vector<std::pair<int, std::function<void()>>> events;

    SDL_Color bg_color;
    void handle_events();
    void process();
};

} // namespace pear

#endif
