#ifndef MAIN_H
#define MAIN_H
#include <Sprite.hpp>
using namespace pear;
class Player : public Sprite
{
public:
  void process();
  Player(Window& window);
  void test();

};
#endif
