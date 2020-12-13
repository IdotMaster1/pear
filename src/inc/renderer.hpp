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
  SDL_Texture* loadTexture(const char* path);
  void renderSprite(SDL_Texture* tex,int x, int y, float scale, double angle = 0);
  void renderFont(SDL_Color color, const char* text, int size, const char* path = "FiraCode-Regular.ttf", int x = 0, int y = 0);
  void updateRenderer();
  void renderPresent();
  void testAnimation();
  SDL_Rect texr;
private:
  SDL_Renderer* renderer;
  SDL_Window* window;

};


#endif
