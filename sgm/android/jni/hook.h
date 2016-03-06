#ifndef HOOK_H
#define HOOK_H

#ifdef __cplusplus
extern "C" {
#endif

  extern void hook_surface_changed(int width, int height);
  extern void hook_draw_frame();

#ifdef __cplusplus
}
#endif


#endif // HOOK_H

