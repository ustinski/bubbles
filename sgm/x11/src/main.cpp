#include "x11.h"

int main()
{
    X11::init();
    X11::mainLoop();
    X11::close();
}
