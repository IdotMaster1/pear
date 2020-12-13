#include "../inc/engine.hpp"
#include <iostream>
Renderer renderer;
void Engine::sleep(int duration)
{
  SDL_Delay(duration * 1000);

}
void Engine::init()
{
  if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
      TTF_Init();
      isRunning = true;
    }
  else
    {
      isRunning = false;
    }

}
void Engine::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);
  switch(event.type)
    {
    case SDL_QUIT:
      isRunning = false;
      break;
    default:
      break;
    }

}
void Engine::update()
{
  cnt++;
}
void Engine::quit()
{
  TTF_Quit();
  SDL_Quit();
  

}

