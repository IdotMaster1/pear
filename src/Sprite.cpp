#include <Sprite.hpp>

using namespace pear;

Sprite::Sprite(std::string path, Vector2 p_position, Window &p_window)
    : window(p_window)
{
    texture = IMG_LoadTexture(window.renderer, path.c_str());
    if (texture == NULL)
    {

        log("Failed to load a texture, error: %s", SDL_GetError());
    }

    int w, h;
    
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    width = w;
    height = h;
    frame.x = 0;
    frame.y = 0;
    frame.w = width;
    frame.h = height;
}
