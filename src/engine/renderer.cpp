
#include "../inc/renderer.hpp"
#include <iostream>

void Renderer::createWindow(const char* title, int w, int h)
{

      window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

}
void Renderer::createRenderer()
{
  renderer = SDL_CreateRenderer(window, -1, 0);

}
void Renderer::setRendererColor(int r,int g, int b, int a)
{

  SDL_SetRenderDrawColor(renderer,r,g,b,a);

}

void Renderer::clearRenderer()
{

  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);

}

void Renderer::destroyRenderer()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

}
void Renderer::renderSprite(const char* path,int x, int y, float scale)
{
  int w, h;
  SDL_Texture* img = IMG_LoadTexture(renderer,path); 
  SDL_QueryTexture(img, NULL, NULL, &w, &h);
  texr.x = x; texr.y = y; texr.w = w * scale  ; texr.h = h * scale; 
  SDL_RenderCopy(renderer, img, NULL, &texr);
  SDL_RenderPresent(renderer);
}

void Renderer::renderFont(SDL_Color color, const char* text, int size,const char* path, int x ,int y)
{
  
  TTF_Font * font = TTF_OpenFont(path,size);
  SDL_Surface * surface = TTF_RenderText_Solid(font,text, color);
  SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = { x, y, texW, texH };
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
  SDL_RenderPresent(renderer);
  SDL_DestroyTexture(texture);
  SDL_FreeSurface(surface);
}

void Renderer::testAnimation()
{
  texr.x += 1;

}
