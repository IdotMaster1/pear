#ifndef PEAR_IMAGE_HPP
#define PEAR_IMAGE_HPP
#include <SDL2/SDL.h>
#include <Vector2.hpp>
namespace pear
{
struct Image
{
    SDL_Rect source;
    SDL_Rect destination;
    SDL_Texture *texture;
};

Image make_image(SDL_Rect frame, Vector2 position, SDL_Texture *texture, float scale = 1);
} // namespace pear

#endif
