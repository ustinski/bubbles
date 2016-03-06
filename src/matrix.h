#ifndef MATRIX_H
#define MATRIX_H

#include "GLES2/gl2.h"

class Vector;

class Matrix
{
public:
    Matrix() { setToIdentity(); }
    Matrix(GLfloat x, GLfloat y, GLfloat z, GLfloat w);
    const GLfloat *data() const { return &_data[0][0]; }
    void setToIdentity();
    void move(const Vector &vector);

    GLfloat *operator [](int index) { return _data[index]; }
    const GLfloat *operator [](int index) const { return _data[index]; }
    friend Matrix operator *(const Matrix &a, const Matrix &b);

private:
    GLfloat _data[4][4];
};

#endif // MATRIX_H
