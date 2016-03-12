#ifndef BUBBLE_H
#define BUBBLE_H


#include "texture.h"
#include "vector.h"

#include <vector>

class Bubble
{
public:
    Bubble(GLfloat r, Vector position);

    Vector position() { return _position; }
    GLfloat radius() { return _r; }

    void draw();
    void update();

private:
    GLfloat _r;
    Vector _position;
    Vector _speed;

    GLfloat *vertexData;
    Texture *refractionMap;
    Texture *outline;

    b2Body *_body;


    void createRefractionMap();
    void createOutline();
    void createPhysics();
};

#endif // BUBBLE_H
