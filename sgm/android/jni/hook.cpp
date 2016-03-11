#include "hook.h"
#include "../../app.h"

#include <time.h>

unsigned int _time;

int _get_time()
{
  struct timeval  now;
  gettimeofday(&now, NULL);
  return (int)(now.tv_sec * 1000 + now.tv_usec / 1000);
}

void hook_surface_changed(int width, int height)
{
    App::init(width, height);
    _time = _get_time();
}

void hook_draw_frame()
{
    int time = _get_time();
    int dt = time - _time;
    _time = time;
    App::update(dt);
}

void hook_pause()
{

}

void hook_resume()
{
    _time = _get_time();
}

void hook_pointer_down(int id, int x, int y)
{
    App::pointerDown(id, x, y);
}

void hook_pointer_up(int id, int x, int y)
{
    App::pointerUp(id, x, y);
}

void hook_pointer_move(int id, int x, int y)
{
    App::pointerMove(id, x, y);
}
