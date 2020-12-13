#ifndef MATH_H
#define MATH_H
#include <iostream>
struct Vector2
{
  Vector2()
    :x(0.0f), y(0.0f)
  {}
  
  float x,y;
  
  Vector2(float p_x,float p_y)
    :x(p_x),y(p_y)
  {}
  void vector2Print()
  {
    std::cout<<x<<", "<<y<<std::endl;
  }
};

#endif
