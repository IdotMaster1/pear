#include "main.hpp"
#include <Pear.hpp>
#include <log.hpp>
using namespace pear;

void Player::process()
{

    Image image = make_image(frame, position);

    SDL_RendererFlip flip = SDL_FLIP_NONE;

    SDL_RenderCopyEx(window.renderer, texture, &image.source, &image.destination, 0, NULL, flip);
}

Player::Player(Window &window) : Sprite("assets/pear.png", Vector2(100, 100), window)
{
    window.register_event(SDL_KEYDOWN, make_method(&Player::test));
    
    window.register_method("process", make_method(&Player::process));
}

void Player::test()
{
    position.x++;
}

int main()
{

    Window window("Hello", 1920, 1080);

    window.background_color((SDL_Color){10, 10, 10});

    Player my_player(window);

    window.show();

    return 0;
}
