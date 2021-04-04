#include "main.hpp"
#include <Pear.hpp>
#include <log.hpp>
using namespace pear;

void Player::process()
{

    Image image = make_image(frame, position, texture);

    window.draw(image);
}

Player::Player(Window &window) : Sprite("assets/pear.png", Vector2(100, 100), window)
{
    window.register_event("arrow_down", make_method(&Player::move_down));
    window.register_method("process", make_method(&Player::process));
}

void Player::move_down()
{
    position.y++;
}

int main()
{

    Window window("Hello", 1920, 1080);

    window.background_color((SDL_Color){10, 10, 10});

    Player my_player(window);

    window.show();

    return 0;
}
