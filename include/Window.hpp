#ifndef PEAR_WINDOW_HPP
#define PEAR_WINDOW_HPP
#include <SDL2/SDL.h>
#include <map>
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

    std::map<std::string, void (*)()> methods;

    void register_event(int event, void (*handler)());
    void show();

private:
    std::string name;
    int width, height;

    bool is_running;
    std::vector<std::pair<int, void (*)()>> events;

    void handle_events();
};

} // namespace pear

#endif
