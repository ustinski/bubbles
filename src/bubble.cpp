#include "bubble.h"
#include "app.h"
#include "program.h"

#include <sstream>

Bubble::Bubble(GLfloat r)
{
    init(r);
}

Bubble::Bubble(const Bubble &bubble)
{
    init(bubble.r());
}

void Bubble::init(GLfloat r)
{
    _r = r;

    const int scale = 2;
    const int w = App::width() * scale / 2;
    const int h = App::height() * scale / 2;
    GLfloat *refractionData = new GLfloat[12] {
            -w, -h,
             w, -h,
             w,  h,
             w,  h,
            -w,  h,
            -w, -h
    };

}

Program *Bubble::program;

void Bubble::createProgram()
{
    program = new Program;
}

GLfloat Bubble::r() const
{
    return _r;
}
