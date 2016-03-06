#include "app.h"
#include "matrix.h"
#include "background.h"

#include "../sgm/app.h"

#include <GLES2/gl2.h>

namespace App
{
    int _width;
    int _height;

    Matrix *_projection;

    Background *_background;

    void initGL();
}

void App::init(int width, int height)
{
    _width = width;
    _height = height;

    _projection = new Matrix(float(2) / _width, float(2) / _height, 1, 1);
    
    initGL();

    _background = new Background;
}

void App::initGL()
{
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glViewport(0, 0, _width, _height);
}

void App::tick(unsigned int dt)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    _background->draw();


    //_background->update(dt);
}

void App::close()
{
}

const Matrix &App::projection() { return *_projection; }

int App::width() { return _width; }
int App::height() { return _height; }
