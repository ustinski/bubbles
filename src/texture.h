#ifndef TEXTURE_H
#define TEXTURE_H

#include <GLES2/gl2.h>

class Program;

class Texture
{
public:
    Texture(int num, Program *program, const char *uniform, int width, int height, unsigned char *pixels);

    unsigned char *pixels;
    GLuint index;
};

#endif // TEXTURE_H
