#ifndef ENTITY_H
#define ENTITY_H
#include <SDL2/SDL.h>
#include "math.hpp"
class Entity
{
public:
  Entity(Vector2 p_position,SDL_Texture* tex);
  Vector2& getPosition()
  {
    return position;
  }
  SDL_Texture* getTex();
  SDL_Rect getCurrentFrame();
private:
  Vector2 position;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};

#endif 
