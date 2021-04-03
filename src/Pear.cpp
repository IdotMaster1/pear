#include <Pear.hpp>
using namespace pear;
Image pear::make_image(SDL_Rect frame, Vector2 position)
{
    SDL_Rect src;

    src.x = frame.x;
    src.y = frame.y;
    src.w = frame.w;
    src.h = frame.h;

    SDL_Rect dst;

    dst.x = position.x;
    dst.y = position.y;
    dst.w = frame.w;
    dst.h = frame.h;

    Image image;

    image.destination = dst;
    image.source = src;

    return image;
}
