#include "vector.h"

#include <math.h>

Vector::Vector(GLfloat x, GLfloat y) : x(coord[0]), y(coord[1])
{
    this->x = x;
    this->y = y;
}

float Vector::length() { return sqrt(x * x + y * y); }

void Vector::operator +=(const Vector &vector)
{
    x += vector.x;
    y += vector.y;
}

void Vector::operator -=(const Vector &vector)
{
    x -= vector.x;
    y -= vector.y;
}

Vector operator /(const Vector &vector, float number)
{
    Vector ans;
    ans.x = vector.x / number;
    ans.y = vector.y / number;
    return ans;
}

Vector operator *(const Vector &vector, float number)
{
    Vector ans;
    ans.x = vector.x * number;
    ans.y = vector.y * number;
    return ans;
}

void Vector::operator =(const Vector &vector)
{
    x = vector.x;
    y = vector.y;
}
