#include <SDL2/SDL.h>
#include "inc/renderer.hpp"
#include "inc/entity.hpp"
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
    // Creates textures
    SDL_Texture* canadaTex = renderer.loadTexture("src/canada.png");
    SDL_Texture* text = renderer.loadTextureFromFont(engine->WHITE,"hello","src/ComicSansMS3.ttf",50);
    Entity flag(100,100,canadaTex);
    // Game loop
    while(engine->running())
      {
	renderer.clearRenderer();
	renderer.renderEntity(flag,10,0.5);
	renderer.renderFont(text);
	engine->handleEvents();
	engine->update();
        renderer.renderPresent();
      }
    engine->quit();
    renderer.destroyRenderer();
  return 0;
}
