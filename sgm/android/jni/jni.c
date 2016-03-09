#include "hook.h"
#include <jni.h>


// JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onLoad(JNIEnv * env, jclass cls) {
// }

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onSurfaceChanged(JNIEnv * env, jclass cls, jint width, jint height) {
    hook_surface_changed(width, height);
}

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onDrawFrame(JNIEnv * env, jclass cls) {
    hook_draw_frame();
}

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onPointerDown(JNIEnv * env, jclass cls, jint id, jint x, jint y) {
    hook_pointer_down(id, x, y);
}

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onPointerUp(JNIEnv * env, jclass cls, jint id, jint x, jint y) {
    hook_pointer_up(id, x, y);
}

JNIEXPORT void JNICALL Java_com_example_bubbles_JNIWrapper_onPointerMove(JNIEnv * env, jclass cls, jint id, jint x, jint y) {
    hook_pointer_move(id, x, y);
}
