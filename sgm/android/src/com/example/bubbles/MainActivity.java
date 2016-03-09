package com.example.bubbles;

import android.app.Activity;
import android.app.ActivityManager;
import android.content.Context;
import android.content.pm.ConfigurationInfo;
import android.opengl.GLSurfaceView;
import android.os.Build;
import android.os.Bundle;
import android.widget.Toast;
import android.view.View.OnTouchListener;
import android.view.View;
import android.view.MotionEvent;

public class MainActivity extends Activity {
    private GLSurfaceView glSurfaceView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        glSurfaceView = new GLSurfaceView(this);
//         glSurfaceView.setEGLConfigChooser(8, 8, 8, 8, 16, 0);
        glSurfaceView.setEGLContextClientVersion(2);
        glSurfaceView.setRenderer(new RendererWrapper());
        setContentView(glSurfaceView);
//         glSurfaceView.setOnTouchListener(new OnTouchListener() {
//             @Override
//             public boolean onTouch(View v, MotionEvent event) {
//                 int action = event.getAction() & MotionEvent.ACTION_MASK;
//                 int pointerIndex = (event.getAction() & MotionEvent.ACTION_POINTER_INDEX_MASK) >> MotionEvent.ACTION_POINTER_INDEX_SHIFT;
//                 int id = event.getPointerId(pointerIndex);
//                 int x = event.getX(pointerIndex);
//                 int y = event.getY(pointerIndex);
// 
//                 switch (action) {
//                 case MotionEvent.ACTION_DOWN:
//                 case MotionEvent.ACTION_POINTER_DOWN:
//                     glSurfaceView.queueEvent(new Runnable() {
//                         @Override
//                         public void run() {
//                             rendererWrapper.handlePointerDown(id, x, y);
//                         }
//                     });
//                     break;
//                 case MotionEvent.ACTION_UP:
//                 case MotionEvent.ACTION_POINTER_UP:
//                 case MotionEvent.ACTION_CANCEL:
//                     glSurfaceView.queueEvent(new Runnable() {
//                         @Override
//                         public void run() {
//                             rendererWrapper.handlePointerUp(id, x, y);
//                         }
//                     });
//                     break;
//                 case MotionEvent.ACTION_MOVE:
//                     glSurfaceView.queueEvent(new Runnable() {
//                         @Override
//                         public void run() {
//                             rendererWrapper.handlePointerMove(id, x, y);
//                         }
//                     });
//                     break;
//                 }
//                 return true;
//             }
//         });
    }

    @Override
    protected void onPause() {
        super.onPause();
    }

    @Override
    protected void onResume() {
        super.onResume();
    }
}
