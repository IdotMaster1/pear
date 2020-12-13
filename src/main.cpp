#include "inc/engine.hpp"
#include "inc/entity.hpp"
#include "inc/math.hpp"
#include "inc/renderer.hpp"
#include "inc/utils.hpp"
#include <SDL2/SDL.h>
#include <vector>
Engine* engine = nullptr;
int main()
{

    // Inititializes objects
    Renderer renderer;
    engine = new Engine();
    engine->init();
    // Creates the main window
    renderer.createWindow("Pear Engine", 1920, 1080);
    // Creates the renderer
    renderer.createRenderer();
    renderer.setRendererColor(209, 206, 49, 1);
    // Creates textures
    SDL_Texture* canadaTex = renderer.loadTexture("src/canada.png");
    SDL_Texture* text = renderer.loadTextureFromFont(engine->WHITE, "hello", "src/ComicSansMS3.ttf", 50);

    Entity flag(Vector2(100,100),canadaTex);
    const float timestep = 0.01f;

    float accumulator = 0.0f;

    float currentTime = utils::getTimeInSeconds();
  
    // Game loop
    while (engine->running()) 
    {
        int startTick = SDL_GetTicks();

        float newTime = utils::getTimeInSeconds();

        float frameTime = newTime - currentTime;

        accumulator += frameTime;
        flag.getPosition().x += 1;
        while (accumulator >= timestep)

        {
            engine->handleEvents();
            accumulator -= timestep;
        }

        renderer.clearRenderer();

        renderer.renderEntity(flag,0,0.5);

        renderer.renderFont(text);

        engine->update();

        renderer.renderPresent();

	int frameTicks = SDL_GetTicks() - startTick;

	if(frameTicks < 1000 / renderer.getRefreshRate())
	  {
	    SDL_Delay(1000 / renderer.getRefreshRate() - frameTicks);
	  }
	
    }

    engine->quit();

    renderer.destroyRenderer();
    return 0;
}
