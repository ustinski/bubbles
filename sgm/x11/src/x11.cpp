#include "x11.h"
#include "../../app.h"


#include <X11/Xlib.h>
#include <EGL/egl.h>

namespace X11
{   
    const char *name = "bubbles-x11";
    
    const int width = 480;
    const int height = 640;
    
    const int x = 0;
    const int y = 0;
    
    Display *x_display;
    Window window;
    EGLSurface egl_surface;
    EGLContext egl_context;
    EGLDisplay egl_display;
}

void X11::init()
{
    x_display = XOpenDisplay(NULL);
//    if (!x_display)
//       printError("couldn't open display");

    egl_display = eglGetDisplay(x_display);
//    if (!egl_display)
//       printError("eglGetDisplay() failed");

    EGLint egl_major, egl_minor;
    eglInitialize(egl_display, &egl_major, &egl_minor);
//    if (!eglInitialize(egl_display, &egl_major, &egl_minor))
//       printError("eglInitialize() failed");

//    s = eglQueryString(egl_display, EGL_VERSION);
//    printLog(std::string("EGL_VERSION = ") + s);

//    s = eglQueryString(egl_display, EGL_VENDOR);
//    printLog(std::string("EGL_VENDOR = ") + s);

//    s = eglQueryString(egl_display, EGL_EXTENSIONS);
//    printLog(std::string("EGL_EXTENSIONS = ") + s);

//    s = eglQueryString(egl_display, EGL_CLIENT_APIS);
//    printLog(std::string("EGL_CLIENT_APIS = ") + s);


    int screenNumber = DefaultScreen(x_display);
    Window rootWindow = RootWindow(x_display, screenNumber);

    EGLConfig config;
        const EGLint attribs[] = {
              EGL_RED_SIZE, 1,
              EGL_GREEN_SIZE, 1,
              EGL_BLUE_SIZE, 1,
              EGL_DEPTH_SIZE, 1,
              EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
              EGL_NONE
        };
        EGLint num_configs;
    eglChooseConfig(egl_display, attribs, &config, 1, &num_configs);
//   if (!eglChooseConfig( egl_display, attribs, &config, 1, &num_configs))
//      printError("couldn't get an EGL visual config\n");

        EGLint vid;
    eglGetConfigAttrib(egl_display, config, EGL_NATIVE_VISUAL_ID, &vid);
//   if (!eglGetConfigAttrib(egl_display, config, EGL_NATIVE_VISUAL_ID, &vid))
//      printError("eglGetConfigAttrib() failed");

   /* The X window visual must match the EGL config */
        XVisualInfo *visInfo, visTemplate;
        int num_visuals;
    visTemplate.visualid = vid;
    visInfo = XGetVisualInfo(x_display, VisualIDMask, &visTemplate, &num_visuals);
//   if (!visInfo)
//      printError("couldn't get X visual");

   /* window attributes */
        XSetWindowAttributes attr;
        attr.background_pixel = 0;
        attr.border_pixel = 0;
        attr.colormap = XCreateColormap(x_display, rootWindow, visInfo->visual, AllocNone);
        attr.event_mask = StructureNotifyMask | ExposureMask | KeyPressMask;
        unsigned long mask = CWBackPixel | CWBorderPixel | CWColormap | CWEventMask;
    window = XCreateWindow(x_display, rootWindow, 0, 0, width, height,
                0, visInfo->depth, InputOutput,
                visInfo->visual, mask, &attr );

   /* set hints and properties */

        XSizeHints sizehints;
        sizehints.x = x;
        sizehints.y = y;
        sizehints.width  = width;
        sizehints.height = height;
        sizehints.flags = USSize | USPosition;
    XSetNormalHints(x_display, window, &sizehints);
    XSetStandardProperties(x_display, window, name, name, None, (char**)NULL, 0, &sizehints);

    eglBindAPI(EGL_OPENGL_ES_API);

        const EGLint ctx_attribs[] = {
           EGL_CONTEXT_CLIENT_VERSION, 2,
           EGL_NONE
        };
    egl_context = eglCreateContext(egl_display, config, EGL_NO_CONTEXT, ctx_attribs );
//   if (!egl_context)
//      printError("eglCreateContext failed");

//   {
//      EGLint val;
//      eglQueryContext(egl_display, egl_context, EGL_CONTEXT_CLIENT_VERSION, &val);
//      printLog(std::string("EGL_CONTEXT_CLIENT_VERSION = ") + toString(val));
//   }

    egl_surface = eglCreateWindowSurface(egl_display, config, window, NULL);
//   if (!*surfRet)
//      printError("eglCreateWindowSurface failed");


   /* sanity checks */
//   {
//      EGLint val;
//      eglQuerySurface(egl_display, *surfRet, EGL_WIDTH, &val);
//      printLog(std::string("EGL_WIDTH = ") + toString(val));
//      eglQuerySurface(egl_display, *surfRet, EGL_HEIGHT, &val);
//      printLog(std::string("EGL_HEIGHT = ") + toString(val));
//      printLog(std::string("\"eglGetConfigAttrib(egl_display, config, EGL_SURFACE_TYPE, &val)\" = ") + toString(eglGetConfigAttrib(egl_display, config, EGL_SURFACE_TYPE, &val)));
//      printLog(std::string("EGL_SURFACE_TYPE = ") + toString(val) + "    EGL_WINDOW_BIT = " + toString(EGL_WINDOW_BIT));
//   }

    XFree(visInfo);
    XMapWindow(x_display, window);

    eglMakeCurrent(egl_display, egl_surface, egl_surface, egl_context);
//    if (!eglMakeCurrent(egl_display, egl_surface, egl_surface, egl_context))
//       printError("eglMakeCurrent() failed");

//   printLog(std::string("GL_RENDERER   = ") + (char*)glGetString(GL_RENDERER));
//   printLog(std::string("GL_VERSION    = ") + (char*)glGetString(GL_VERSION));
//   printLog(std::string("GL_VENDOR     = ") + (char*)glGetString(GL_VENDOR));
//   printLog(std::string("GL_EXTENSIONS = ") + (char*)glGetString(GL_EXTENSIONS));


//    if(!eglGetProcAddress("glMapBufferOES"));
//        printLog(std::string("\"eglGetProcAddress(\"glMapBufferOES\")\" == 0"));

    Atom WM_DELETE_WINDOW = XInternAtom(x_display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(x_display, window, &WM_DELETE_WINDOW, 1);

    App::init(width, height);
}

void X11::mainLoop()
{
    for(;;) {
        XEvent event;
        while(XPending(x_display)) {
            XNextEvent(x_display, &event);

            /*switch (event.type) {
                case ConfigureNotify:
                    reshape(event.xconfigure.width, event.xconfigure.height);
                    break;
            case KeyPress:
            {
                char buffer[10];
                int r, code;
                code = XLookupKeysym(&event.xkey, 0);
                if (code == XK_Left) {

                }
                else if (code == XK_Right) {

                }
                else if (code == XK_Up) {

                }
                else if (code == XK_Down) {

                }
                else {
                    r = XLookupString(&event.xkey, buffer, sizeof(buffer),
                                    NULL, NULL);
                    if (buffer[0] == 27)
                    return;
                }
            }
            break;
            }*/

            switch(event.type) {
            case ClientMessage:
                return;
            }
        }

        App::tick(123456);
        eglSwapBuffers(egl_display, egl_surface);
    }
}

void X11::close()
{
    App::close();

    eglDestroyContext(egl_display, egl_context);
    eglDestroySurface(egl_display, egl_surface);
    eglTerminate(egl_display);

    XDestroyWindow(x_display, window);
    XCloseDisplay(x_display);
}


//void App::printLog(std::string str)
//{
//    std::cout << str << '\n';
//}

//void App::printError(std::string str)
//{
//    std::cerr << str << '\n';
//}
