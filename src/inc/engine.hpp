#ifndef ENGINE_H
#define ENGINE_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h" 
class Engine
{
public:
  void init();
  void sleep(int duration);
  void quit();
  SDL_Color WHITE  = {255,255,255};
};


#endif
