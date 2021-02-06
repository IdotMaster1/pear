#ifndef ENGINE_H
#define ENGINE_H
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "renderer.hpp"
#include "utils.hpp"

class Engine
{
public:
  void init();
  void sleep(int duration);
  void quit();
  void loop(Renderer& renderer);
  bool running() {return isRunning;};
  void handleEvents();
  void process();
  SDL_Color WHITE  = {255,255,255};
  SDL_Color BLUE = {255,0,255};
  SDL_Color GREEN = {0,255,0};
  SDL_Color RED = {255,0,0};
  SDL_Color BLACK = {0,0,0};
private:
  bool isRunning;
  int cnt = 0;
};


#endif
