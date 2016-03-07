#include "vector.h"

#include <math.h>

Vector::Vector(GLfloat x, GLfloat y)
{
    setValues(x, y);
}

float Vector::length() const
{
    return sqrt(lengthSquare());
}

float Vector::lengthSquare() const
{
    return coord[0] * coord[0] + coord[1] * coord[1];
}

const GLfloat *Vector::data() const
{
    return coord;
}

void Vector::operator +=(const Vector &vector)
{
    coord[0] += vector.x();
    coord[1] += vector.y();
}

void Vector::operator -=(const Vector &vector)
{
    coord[0] -= vector.x();
    coord[1] -= vector.y();
}

Vector operator /(const Vector &vector, float number)
{
    return Vector(vector.x() / number, vector.y() / number);
}

Vector operator *(const Vector &vector, float number)
{
    return Vector(vector.x() * number, vector.y() * number);
}

void Vector::operator =(const Vector &vector)
{
    setValues(vector.x(), vector.y());
}

GLfloat Vector::x() const
{
    return coord[0];
}

GLfloat Vector::y() const
{
    return coord[1];
}

void Vector::setValues(GLfloat x, GLfloat y)
{
    coord[0] = x;
    coord[1] = y;
}
