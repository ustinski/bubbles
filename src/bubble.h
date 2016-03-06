#ifndef BUBBLE_H
#define BUBBLE_H

#include <GLES2/gl2.h>

class Program;

class Bubble
{
public:
    Bubble(GLfloat r);
    Bubble(const Bubble &bubble);

    GLfloat r() const;

    static void createProgram();

private:
    GLfloat _r;
    static Program *program;


    void init(GLfloat r);

};

#endif // BUBBLE_H
