#ifndef VECTOR_H
#define VECTOR_H

#include "gles.h"

#include <Box2D/Box2D.h>

class Vector
{
public:
    Vector(GLfloat x = 0, GLfloat y = 0);

    GLfloat x() const;
    GLfloat y() const;

    void setValues(GLfloat x, GLfloat y);
    float length() const;
    float lengthSquare() const;
    const GLfloat *data() const;

    void operator +=(const Vector &vector);
    void operator -=(const Vector &vector);
    friend Vector operator -(Vector a, Vector b);
    friend Vector operator /(const Vector &vector, float number);
    friend Vector operator *(const Vector &vector, float number);
    void operator =(const Vector &vector);
    void operator =(b2Vec2 vector);

private:
    GLfloat coord[2];
};

#endif // VECTOR_H
