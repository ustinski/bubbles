#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "program.h"
#include "texture.h"
#include "color.h"

struct ColorPair
{
    Color a, b;
};

class ColorContainer : public vector<ColorPair>
{
public:
    const ColorPair &current() { return at(_current); }
    const ColorPair &next() { return at((_current + 1) % size()); }

    void change() { ++_current %= size(); }

private:
    int _current = 3;
};

class Background
{
public:
    Background();

    void draw();
    void update(int dt);

    GLuint textureIndex() const { return background->index; }

private:
    GLfloat *vertexData;

    Texture *background;

    ColorContainer colors;
    int time;
    bool changeColor;

    Program *program;
    void createProgram();
    void initColors();
    void createTexture();
        void fill(const ColorPair &pair);
};

#endif // BACKGROUND_H
