#ifndef ENTITY_H
#define ENTITY_H
#include <SDL2/SDL.h>
class Entity
{
public:
  Entity(float position_x, float position_y,SDL_Texture* tex);
  float getX();
  float getY();
  SDL_Texture* getTex();
  SDL_Rect getCurrentFrame();
private:
  float x,y;
  SDL_Rect currentFrame;
  SDL_Texture* tex;
};

#endif 
