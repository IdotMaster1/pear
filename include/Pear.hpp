#ifndef PEAR_HPP
#define PEAR_HPP
#include <functional>
#include <Window.hpp>
#include <Vector2.hpp>
#include <Sprite.hpp>
namespace pear
{
#define make_method(x) std::bind(x, this)

struct Image
{
    SDL_Rect source;
    SDL_Rect destination;
};

Image make_image(SDL_Rect frame, Vector2 position);

} // namespace pear

#endif
