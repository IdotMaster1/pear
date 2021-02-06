#include "inc/engine.hpp"
#include "inc/entity.hpp"
#include "inc/math.hpp"
#include "inc/renderer.hpp"
#include "inc/utils.hpp"
#include <SDL2/SDL.h>
#include <vector>
Engine* engine = nullptr;
Renderer renderer;
Entity* pear;
Entity* myText;
void Engine::process()
{
    pear->getPosition().y += 1;
    renderer.renderEntity(*pear,0,2);
    renderer.renderEntity(*myText,0,1 );
    
}
int main()
{


    engine = new Engine();

    engine->init();

    renderer.createWindow("Pear Engine", 1920, 1080);

    renderer.createRenderer();
    renderer.setClearColor(209, 206, 49, 1);
    renderer.clearRenderer();
    SDL_Texture* pearTex = renderer.loadTexture("assets/pear.png");
    SDL_Texture* text = renderer.loadTextureFromFont(engine->WHITE, "The pear game engine", "src/ComicSansMS3.ttf", 50);
    
    pear = new Entity(Vector2(100,100),pearTex);
    myText = new Entity(Vector2(0,0),text);
    
    engine->loop(renderer);

    delete engine;
    return 0;
}
