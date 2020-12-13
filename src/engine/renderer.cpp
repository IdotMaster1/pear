
#include "../inc/renderer.hpp"
#include <iostream>
void Renderer::createWindow(const char* title, int w, int h)
{

      window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

}
void Renderer::createRenderer()
{
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

}
void Renderer::setRendererColor(int r,int g, int b, int a)
{

  SDL_SetRenderDrawColor(renderer,r,g,b,a);

}

void Renderer::clearRenderer()
{

  SDL_RenderClear(renderer);

}
void Renderer::renderPresent()
{
  SDL_RenderPresent(renderer);
}
int Renderer::getRefreshRate()
{
  int displayIndex = SDL_GetWindowDisplayIndex(window);
  SDL_DisplayMode mode;
  SDL_GetDisplayMode(displayIndex,0,&mode);
  return mode.refresh_rate;
}
void Renderer::destroyRenderer()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);

}
SDL_Texture* Renderer::loadTexture(const char* path)
{
  SDL_Texture* texture = NULL;
  texture = IMG_LoadTexture(renderer,path);
  if(texture == NULL)
    {

      std::cout<<"Pear failed to load a texture, error: "<<SDL_GetError()<<std::endl;
    }
  return texture;
}
SDL_Texture* Renderer::loadTextureFromFont(SDL_Color color,const char* text,const char* path,int size)
{
  SDL_Texture* texture = NULL;
  TTF_Font * font = TTF_OpenFont(path,size);
  SDL_Surface * surface = TTF_RenderText_Solid(font,text, color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  if (texture == NULL)
    {
      std::cout<<"Pear failed to load a texture, error: "<<SDL_GetError()<<std::endl;
    }
  return texture;
}
void Renderer::renderEntity(Entity& entity,double angle, float scale)
{ 
  SDL_Rect src;
  
  src.x = entity.getCurrentFrame().x;
  src.y = entity.getCurrentFrame().y;
  src.w = entity.getCurrentFrame().w;
  src.h = entity.getCurrentFrame().h;

  SDL_Rect dst;
  
  dst.x = entity.getPosition().x;
  dst.y = entity.getPosition().y;
  dst.w = entity.getCurrentFrame().w * scale;
  dst.h = entity.getCurrentFrame().h * scale;
  
  SDL_RendererFlip flip = SDL_FLIP_HORIZONTAL;
  
  SDL_RenderCopyEx(renderer, entity.getTex(), &src, &dst,angle,NULL,flip);
}

void Renderer::renderFont(SDL_Texture* texture,int x ,int y)
{
  int texW = 0;
  int texH = 0;
  SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
  SDL_Rect dstrect = { x, y, texW, texH };
  SDL_RenderCopy(renderer, texture, NULL, &dstrect);
}

