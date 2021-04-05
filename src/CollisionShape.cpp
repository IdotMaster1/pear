#include <CollisionShape.hpp>

using namespace pear;

bool CollisionShape::is_colliding(CollisionShape second)
{
    //The sides of the rectangles
    int left_a, left_b;
    int right_a, right_b;
    int top_a, top_b;
    int bottom_a, bottom_b;

    left_a = position.x;
    right_a = position.x + width;
    top_a = position.y;
    bottom_a = position.y + height;

    //Calculate the sides of rect B
    left_b = second.position.x;
    right_b = second.position.x + second.width;
    top_b = second.position.y;
    bottom_b = second.position.y + second.height;

    if (bottom_a <= top_b)
    {
        return false;
    }

    if (top_a >= bottom_b)
    {
        return false;
    }

    if (right_a <= left_b)
    {
        return false;
    }

    if (left_a >= right_b)
    {
        return false;
    }

    return true;
}

CollisionShape::CollisionShape(int w, int h, Vector2 pos)
{
    width = w;
    height = h;
    position = pos;
}
