#include <Image.hpp>
using namespace pear;
Image pear::make_image(SDL_Rect frame, Vector2 position, SDL_Texture *texture, float scale)
{
    SDL_Rect src;

    src.x = frame.x;
    src.y = frame.y;
    src.w = frame.w;
    src.h = frame.h;

    SDL_Rect dst;

    dst.x = position.x;
    dst.y = position.y;
    dst.w = frame.w * scale;
    dst.h = frame.h * scale;

    Image image;

    image.destination = dst;
    image.source = src;
    image.texture = texture;

    return image;
}
