#include "inc/engine.hpp"
#include "inc/entity.hpp"
#include "inc/math.hpp"
#include "inc/renderer.hpp"
#include "inc/utils.hpp"
#include <SDL2/SDL.h>
#include <vector>
Engine* engine = nullptr;
Renderer renderer;
Entity* flag;
SDL_Texture* text;

void Engine::process()
{
    flag->getPosition().x += 1;
    renderer.renderEntity(*flag);
    renderer.renderFont(text);
}

int main()
{


    engine = new Engine();

    engine->init();

    renderer.createWindow("Pear Engine", 1920, 1080);

    renderer.createRenderer();

    renderer.setRendererColor(209, 206, 49, 1);

    renderer.clearRenderer();

    SDL_Texture* canadaTex = renderer.loadTexture("src/canada.png");
    text = renderer.loadTextureFromFont(engine->WHITE, "The pear game engine", "src/ComicSansMS3.ttf", 50);
    flag = new Entity(Vector2(100,100),canadaTex);

    engine->loop(renderer);
    delete engine;
    return 0;
}
