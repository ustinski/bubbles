package com.example.bubbles;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;
import android.util.Log;

public class RendererWrapper implements Renderer {
     @Override
     public void onSurfaceCreated(GL10 gl, EGLConfig config) {
     }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height) {
        Log.d("MyActivity", "w="+width+"h="+height);
        JNIWrapper.onSurfaceChanged(width, height);
    }

    @Override
    public void onDrawFrame(GL10 gl) {
        JNIWrapper.onDrawFrame();
    }

    public void handlePointerDown(int id, int x, int y) {
        JNIWrapper.onPointerDown(id, x, y);
    }

    public void handlePointerUp(int id, int x, int y) {
        JNIWrapper.onPointerUp(id, x, y);
    }

    public void handlePointerMove(int id, int x, int y) {
        JNIWrapper.onPointerMove(id, x, y);
    }
}
