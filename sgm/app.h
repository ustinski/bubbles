#ifndef L_APP_H
#define L_APP_H

namespace App
{
    void init(int width, int height);
    void update(int dt);
    void pointerDown(int id, int x, int y);
    void pointerUp(int id, int x, int y);
    void pointerMove(int id, int x, int y);
    void close();
}

#endif // L_APP_H
