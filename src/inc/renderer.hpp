#ifndef RENDERER_H
#define RENDERER_H
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <string>
#include "entity.hpp"
class Renderer
{
public:
  void createWindow(const char* title,int w, int h);
  void createRenderer();
  void setRendererColor(int r, int g, int b, int a);
  void clearRenderer();
  void destroyRenderer();
  SDL_Texture* loadTexture(const char* path);
  SDL_Texture* loadTextureFromFont(SDL_Color color,const char* text, const char* path = "FiraCode-Regular.ttf", int size = 60);
  void renderEntity(Entity& entity,double angle = 0, float scale = 1);
  void renderFont(SDL_Texture* texture,int x = 0, int y = 0);
  void updateRenderer();
  void renderPresent();
private:
  SDL_Renderer* renderer;
  SDL_Window* window;

};


#endif
