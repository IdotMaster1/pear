#include <Window.hpp>
#include <log.hpp>

using namespace pear;

void test()
{
    log("test");
}

int main()
{

    Window window("Hello", 1920, 1080);

    window.register_event(SDL_KEYDOWN, &test);
    
    window.show();
    
    return 0;
}
