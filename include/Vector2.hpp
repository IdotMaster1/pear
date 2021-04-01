#ifndef PEAR_VECTOR2_HPP
#define PEAR_VECTOR2_HPP

struct Vector2
{
    Vector2()
        : x(0.0f), y(0.0f)
    {
    }

    float x, y;

    Vector2(float p_x, float p_y)
        : x(p_x), y(p_y)
    {
    }
};

#endif
