#ifndef MAIN_H
#define MAIN_H
#include <Sprite.hpp>
using namespace pear;
class Player : public Sprite
{
public:
  void process();
  Player(Window& window);
  void move_down();
  void move_up();
  void move_right();
  void move_left();

private:
  int y_dir,x_dir;

};
#endif
