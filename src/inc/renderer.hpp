#ifndef RENDERER_H
#define RENDERER_H
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
class Renderer
{
public:
  void createWindow(const char* title,int w, int h);
  void createRenderer();
  void setRendererColor(int r, int g, int b, int a);
  void clearRenderer();
  void destroyRenderer();
  void renderSprite(const char* path, int x, int y, float scale);
  void renderFont(SDL_Color color, const char* text, int size, const char* path = "FiraCode-Regular.ttf", int x = 0, int y = 0);
  void updateRenderer();
  void testAnimation();
private:
  SDL_Renderer* renderer;
  SDL_Window* window;
  SDL_Rect texr;

};


#endif
