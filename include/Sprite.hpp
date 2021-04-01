#ifndef PEAR_SPRITE_HPP
#define PEAR_SPRITE_HPP
#include <SDL2/SDL_image.h>
#include <Vector2.hpp>
#include <Window.hpp>
#include <log.hpp>
#include <memory>
namespace pear
{

class Sprite
{
public:
    float opacity;
    Vector2 position;

    Sprite(std::string path, Vector2 p_position, Window &p_window);

    Window &window;

protected:
    SDL_Texture *texture;
    SDL_Rect frame;
    int width, height;
};

} // namespace pear

#endif
