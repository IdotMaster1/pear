#include "main.hpp"
#include <Sprite.hpp>
#include <Window.hpp>
#include <log.hpp>
using namespace pear;

void test()
{
    log("test");
}

void Player::process()
{
    SDL_Rect src;

    src.x = frame.x;
    src.y = frame.y;
    src.w = frame.w;
    src.h = frame.h;

    SDL_Rect dst;

    dst.x = position.x;
    dst.y = position.y;
    dst.w = frame.w;
    dst.h = frame.h;

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RenderCopyEx(window.renderer, texture, &src, &dst, 0, NULL, flip);
}

Player::Player(Window &window) : Sprite("assets/pear.png", Vector2(100, 100), window)
{

  //window.register_method("process", &Player::process);
}

int main()
{

    Window window("Hello", 1920, 1080);

    window.register_event(SDL_KEYDOWN, &test);

    window.background_color((SDL_Color){10, 10, 10});

    Player my_player(window);

    window.show();

    return 0;
}
