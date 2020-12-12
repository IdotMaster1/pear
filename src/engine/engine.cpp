#include "../inc/engine.hpp"

void Engine::sleep(int duration)
{
  SDL_Delay(duration * 1000);

}
void Engine::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();

}

void Engine::quit()
{
  TTF_Quit();
  SDL_Quit();
  

}
