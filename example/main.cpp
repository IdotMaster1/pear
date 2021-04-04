#include "main.hpp"
#include <Pear.hpp>
#include <log.hpp>
using namespace pear;

void Player::process()
{

    Image image = make_image(frame, position, texture);
    window.draw(image);
    position.x += x_dir;
    position.y += y_dir;
}

Player::Player(Window &window) : Sprite("assets/pear.png", Vector2(500, 100), window)
{

    window.register_event("w", make_method(&Player::move_up));
    window.register_event("a", make_method(&Player::move_left));
    window.register_event("s", make_method(&Player::move_down));
    window.register_event("d", make_method(&Player::move_right));

    window.register_method("process", make_method(&Player::process));
}

void Player::move_down()
{
    y_dir = 2;
    x_dir = 0;
}
void Player::move_up()
{
    y_dir = -2;
    x_dir = 0;
}
void Player::move_right()
{
    x_dir = 2;
    y_dir = 0;
}
void Player::move_left()
{
    x_dir = -2;
    y_dir = 0;
}

int main()
{

    Window window("Hello", 1920, 1080);

    window.background_color((SDL_Color){40, 40, 40});

    Player my_player(window);
    window.show();

    return 0;
}
