#include "../inc/entity.hpp"

Entity::Entity(Vector2 p_position,SDL_Texture* tex)
  :position(p_position),tex(tex)
{
  int w,h;
  SDL_QueryTexture(tex, NULL, NULL, &w, &h);
  currentFrame.x = 0;
  currentFrame.y = 0;
  currentFrame.w = w;
  currentFrame.h = h;

}
SDL_Texture* Entity::getTex()
{
  return tex;
}

SDL_Rect Entity::getCurrentFrame()
{
  return currentFrame;
}
