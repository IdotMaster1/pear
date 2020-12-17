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
private:
  bool isRunning;
  int cnt = 0;
};


#endif
