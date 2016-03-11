package com.example.bubbles;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.widget.Toast;
import android.view.View;
import android.view.MotionEvent;

public class MainActivity extends Activity {
    private GLSurfaceView glSurfaceView;
    private boolean rendererSet;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        glSurfaceView = new GLSurfaceView(this);
        if (isEmulator()) {
            glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        }
        glSurfaceView.setEGLContextClientVersion(2);
        glSurfaceView.setRenderer(new RendererWrapper());
        rendererSet = true;
        setContentView(glSurfaceView);
        glSurfaceView.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                int action = event.getAction() & MotionEvent.ACTION_MASK;
                int pointerIndex = (event.getAction() & MotionEvent.ACTION_POINTER_INDEX_MASK) >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
                int id = event.getPointerId(pointerIndex);
                int x = Math.round(event.getX(pointerIndex));
                int y = Math.round(event.getY(pointerIndex));

                switch (action) {
                case MotionEvent.ACTION_DOWN:
                case MotionEvent.ACTION_POINTER_DOWN:
                    JNIWrapper.onPointerDown(id, x, y);
                    break;
                case MotionEvent.ACTION_UP:
                case MotionEvent.ACTION_POINTER_UP:
                case MotionEvent.ACTION_CANCEL:
                    JNIWrapper.onPointerUp(id, x, y);
                    break;
                case MotionEvent.ACTION_MOVE:
                    JNIWrapper.onPointerMove(id, x, y);
                    break;
                }
                return true;
            }
        });
    }

    private boolean isEmulator() {
        return Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
              && (Build.FINGERPRINT.startsWith("generic")
              || Build.FINGERPRINT.startsWith("unknown")
              || Build.MODEL.contains("google_sdk")
              || Build.MODEL.contains("Emulator")
              || Build.MODEL.contains("Android SDK built for x86"));
    }

    @Override
    protected void onPause() {
        super.onPause();
        if (rendererSet) {
            glSurfaceView.onPause();
            JNIWrapper.onPause();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if (rendererSet) {
            glSurfaceView.onResume();
            JNIWrapper.onResume();
        }
    }
}
