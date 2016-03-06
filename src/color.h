#ifndef COLOR_H
#define COLOR_H

typedef unsigned char uchar;

struct Color
{
    Color(uchar rr, uchar gg, uchar bb) : r(rr), g(gg), b(bb) {}

    uchar r, g, b;
};

#endif // COLOR_H
