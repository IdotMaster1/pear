#include <SDL2/SDL.h>
#include "inc/renderer.hpp"
#include "inc/engine.hpp"
int main()
{

    Renderer renderer;
    Engine engine;
    engine.init();
    renderer.createWindow("hello", 1920, 1080);
    renderer.createRenderer();
    renderer.setRendererColor(0, 140, 255 ,255);
    renderer.clearRenderer();
    renderer.renderSprite("src/canada.png", 100, 200, 1);
    renderer.renderFont(engine.WHITE,"hello world",40);
    engine.sleep(3);
    renderer.destroyRenderer();
    engine.quit();
  return 0;
}
