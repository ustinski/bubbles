#ifndef TEXTURE_H
#define TEXTURE_H

#include "gles.h"

class Program;

struct Texture
{
    Texture(int number, Program *program, const char *uniform, int width, int height, unsigned char *pixels);

    void bind();

    int number;
    GLuint index;
    unsigned char *pixels;
};

#endif // TEXTURE_H
