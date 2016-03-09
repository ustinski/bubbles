package com.example.bubbles;

public class JNIWrapper {
    static {
        System.loadLibrary("app");
    }

    public static native void onSurfaceChanged(int width, int height);

    public static native void onDrawFrame();

    public static native void onPointerDown(int id, int x, int y);

    public static native void onPointerUp(int id, int x, int y);

    public static native void onPointerMove(int id, int x, int y);
}
