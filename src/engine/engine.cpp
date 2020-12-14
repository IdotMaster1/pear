#include "../inc/engine.hpp"
#include <iostream>
Engine* engine_obj = nullptr;
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
void Engine::loop(Renderer& renderer)
{
    const float timestep = 0.01f;
    float accumulator = 0.0f;

    float currentTime = utils::getTimeInSeconds();
  
    // Game loop
    while (running()) 
    {   
        int startTick = SDL_GetTicks();

        float newTime = utils::getTimeInSeconds();

        float frameTime = newTime - currentTime;

        accumulator += frameTime;
        while (accumulator >= timestep)

        {
            handleEvents();
            accumulator -= timestep;
        }

        renderer.clearRenderer();

        process();

        update();

        renderer.renderPresent();

    int frameTicks = SDL_GetTicks() - startTick;

    if(frameTicks < 1000 / renderer.getRefreshRate())
      {
        SDL_Delay(1000 / renderer.getRefreshRate() - frameTicks);
      }
    
    }

    quit();

    renderer.destroyRenderer();
}
