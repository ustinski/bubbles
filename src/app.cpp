#include "app.h"
#include "background.h"
#include "bubblecontainer.h"

#include "../sgm/app.h"

#include "gles.h"

#include <Box2D/Box2D.h>

namespace App
{
    int _width;
    int _height;

    b2World *_world;
    const double _scale = 10;

    Background *_background;

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

    _world = new b2World(b2Vec2(0, 0));

    _background = new Background;
    BubbleContainer::init();

    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
    BubbleContainer::add();
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
    BubbleContainer::draw();


    _world->Step(double(dt) / 1000, 6, 2);

    _background->update(dt);
    BubbleContainer::update();
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

b2World *App::world()
{
    return _world;
}

double App::scale()
{
    return _scale;
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
