#ifndef PEAR_HPP
#define PEAR_HPP
#include <functional>
#include "Window.hpp"
#include "Vector2.hpp"
#include "Sprite.hpp"
#include "CollisionShape.hpp"
namespace pear
{
#define make_method(x) std::bind(x, this)



Image make_image(SDL_Rect frame, Vector2 position);

} // namespace pear

#endif
