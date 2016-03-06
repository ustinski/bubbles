#include "texture.h"
#include "program.h"

Texture::Texture(int num, Program *program, const char *uniform, int width, int height, unsigned char *pixels)
{
    glActiveTexture(GL_TEXTURE0 + num);
    glGenTextures(1, &index);
    glBindTexture(GL_TEXTURE_2D, index);
    glUniform1i(glGetUniformLocation(program->index(), uniform), 0);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
    this->pixels = pixels;

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
