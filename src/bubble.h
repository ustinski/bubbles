#ifndef BUBBLE_H
#define BUBBLE_H

#include "program.h"
#include "texture.h"
#include "vector.h"

class Bubble
{
public:
    static void initCommon();

    Bubble(GLfloat r);

    void draw();
    void update(int dt);

private:
    GLfloat _r;
    Vector _position;
    Vector _speed;

    GLfloat *vertexData;
    Texture *refractionMap;
    Texture *outline;
    static Program *program;

    static void createProgram();
    static void createBackgroundTexture();
    void createRefractionMap();
    void createOutline();
};

#endif // BUBBLE_H
