#ifndef APP_H
#define APP_H

class b2World;
class Background;

namespace App
{
    int width();
    int height();

    b2World *world();
    double scale();

    const Background &background();
}

#endif // APP_H
