#ifndef PEAR_COLLISION_HPP
#define PEAR_COLLISION_HPP
#include "Vector2.hpp"
namespace pear
{
class CollisionShape
{
public:
    bool is_colliding(CollisionShape second);
    CollisionShape(int w, int h, Vector2 pos);

    Vector2 position;
    int width, height;
};
} // namespace pear

#endif
