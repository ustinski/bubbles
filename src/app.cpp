#include "app.h"
#include "background.h"
#include "bubble.h"

#include "../sgm/app.h"

#include <GLES2/gl2.h>

namespace App
{
    int _width;
    int _height;

    Background *_background;
    Bubble *bubble;
    Bubble *b1;


    void initGL();
}

void App::init(int width, int height)
{
    static bool a = false;
    if(a) return;
    else a = true;
    
    _width = width;
    _height = height;
    
    initGL();

    _background = new Background;
     Bubble::initCommon();
     b1 = new Bubble(100);
     bubble = new Bubble(120);

}

void App::initGL()
{
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, _width, _height);
}

void App::update(int dt)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _background->draw();
     bubble->draw();
     b1->draw();


    _background->update(15);
    bubble->update(15);
    b1->update(15);
}

void App::close()
{
}

int App::width()
{
    return _width;
}

int App::height()
{
    return _height;
}

const Background &App::background()
{
    return *_background;
}


void App::pointerDown(int id, int x, int y)
{

}

void App::pointerUp(int id, int x, int y)
{

}

void App::pointerMove(int id, int x, int y)
{

}
