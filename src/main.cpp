#include <SDL2/SDL.h>
#include "inc/renderer.hpp"
#include "inc/engine.hpp"
Engine *engine = nullptr;
int main()
{

    // Inititializes objects
    Renderer renderer;
    engine = new Engine();
    engine->init();
    // Creates the main window
    renderer.createWindow("hello", 1920, 1080);
    // Creates the renderer
    renderer.createRenderer();
    // Sets the renderer to have a blue background
    renderer.setRendererColor(0, 140, 255, 1);
    // Clears the renderer
    renderer.clearRenderer();
    // Creates a texture
    SDL_Texture* canadaTex = renderer.loadTexture("src/canada.png");
    // Game loop
    while(engine->running())
      {
	renderer.clearRenderer();
	renderer.renderSprite(canadaTex,100,100,1,0);
	engine->handleEvents();
	engine->update();
        renderer.renderPresent();
      }
    engine->quit();
    renderer.destroyRenderer();
  return 0;
}
