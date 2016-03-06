#include "matrix.h"
#include "vector.h"

Matrix::Matrix(GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
        if(i != j) _data[i][j] = 0;

    _data[0][0] = x;
    _data[1][1] = y;
    _data[2][2] = z;
    _data[3][3] = w;
}

Matrix operator *(const Matrix &a, const Matrix &b)
{
    Matrix ans;
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++) {
        ans[i][j] = 0;
        for(int k = 0; k < 4; k++) ans[i][j] += a[i][k] * b[k][j];
    }
    return ans;
}

void Matrix::setToIdentity()
{
    for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
        _data[i][j] = i == j;
}

void Matrix::move(const Vector &vector)
{
    _data[0][3] += vector.x;
    _data[1][3] += vector.y;
}
