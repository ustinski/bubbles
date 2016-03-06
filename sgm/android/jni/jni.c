#include "hook.h"
#include <jni.h>

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onSurfaceChanged(JNIEnv * env, jclass cls, jint width, jint height) {
    hook_surface_changed(width, height);
}

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onDrawFrame(JNIEnv * env, jclass cls) {
    hook_draw_frame();
}
