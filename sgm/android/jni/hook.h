#ifndef HOOK_H
#define HOOK_H

#ifdef __cplusplus
extern "C" {
#endif

  extern void hook_surface_changed(int width, int height);
  extern void hook_draw_frame();
  extern void hook_pointer_down(int id, int x, int y);
  extern void hook_pointer_up(int id, int x, int y);
  extern void hook_pointer_move(int id, int x, int y);

#ifdef __cplusplus
}
#endif


#endif // HOOK_H

