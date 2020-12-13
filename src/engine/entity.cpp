#include "../inc/entity.hpp"

Entity::Entity(float position_x, float position_y,SDL_Texture* tex)
  :x(position_x),y(position_y),tex(tex)
{
  int w,h;
  SDL_QueryTexture(tex, NULL, NULL, &w, &h);
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = w;
  currentFrame.h = h;

}
float Entity::getX()
{
  return x;
}
float Entity::getY()
{
  return y;
}
SDL_Texture* Entity::getTex()
{
  return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
  return currentFrame;
}
