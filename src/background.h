#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "program.h"
#include "texture.h"

struct Color
{
    Color(unsigned char rr, unsigned char gg, unsigned char bb) : r(rr), g(gg), b(bb) {}

    unsigned char r, g, b;
};

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

    Texture texture() const;

private:
    GLfloat *vertexData;
    Texture *_texture;
    Program program;

    ColorContainer colors;
    int time;
    bool changeColor;


    void createProgram();
    void initColors();
    void createTexture();
        void fill(const ColorPair &pair);
    void createPhysics();
        void createBox(int x, int y, int hWidth, int hHeight);
};

#endif // BACKGROUND_H
