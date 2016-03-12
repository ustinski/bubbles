#include "background.h"
#include "app.h"

#include <iostream>
#include <sstream>

#include <Box2D/Box2D.h>

using namespace std;
using namespace App;

Background::Background()
    : time(0)
    , changeColor(false)
{
    GLfloat w = width() / 2;
    GLfloat h = height() / 2;

    vertexData = new GLfloat[12] {
        -w, -h,
         w, -h,
         w,  h,
         w,  h,
        -w,  h,
        -w, -h
    };

    createProgram();
    initColors();
    createTexture();
    createPhysics();
}

void Background::createProgram()
{
    stringstream vertex;
    vertex <<   "precision mediump float;"
                ""
                "attribute vec2 a_position;"
                ""
                "varying vec2 v_position;"
                ""
                "void main()"
                "{"
                ""
                "    gl_Position = vec4(a_position * 2.0 / vec2(" << width() << ", " << height() << "), 0, 1);"
                ""
                "    v_position = a_position;"
                "}";
    stringstream fragment;
    fragment << "precision mediump float;"
                ""
                "uniform sampler2D u_background;"
                ""
                "varying vec2 v_position;"
                ""
                "void main()"
                "{"
                "    gl_FragColor = texture2D(u_background, v_position / vec2(" << width() << ", " << height() << ") + vec2(0.5));"
                "}";
    program.setShaders(vertex, fragment);

    program.addAttribute("a_position", 2, 2, 0);
}

void Background::initColors()
{
    colors.push_back({{184, 0, 184}, {107, 0, 184}});
    colors.push_back({{107, 0, 184}, {31, 0, 184}});
    colors.push_back({{31, 0, 184}, {0, 46, 184}});
    colors.push_back({{0, 46, 184}, {0, 123, 184}});
    colors.push_back({{0, 123, 184}, {0, 184, 169}});
    colors.push_back({{7, 154, 90}, {46, 184, 82}});
    colors.push_back({{169, 184, 0}, {184, 123, 0}});
    colors.push_back({{184, 123, 0}, {184, 46, 0}});
    colors.push_back({{184, 46, 0}, {184, 0, 31}});
    colors.push_back({{184, 28, 70}, {154, 0, 89}});
}

void Background::createTexture()
{
    unsigned char *pixels = new unsigned char[height() * width() * 4];
    for(int i = 0; i < height(); i++) for(int j = 0; j < width(); j++)
            pixels[(width() * i + j) * 4 + 3] = 255;
    _texture = new Texture(0, &program, "u_background", width(), height(), pixels);
    fill(colors.current());
}

void Background::fill(const ColorPair &pair)
{
        const double scale = 0.05;
        const int max = height() > width() ? height() : width();
        const int lineSize = max * scale;
    for(int i = 0; i < height(); i++) {
        const Color &c = i % (lineSize * 2) >= lineSize ? pair.a : pair.b;
        for(int j = 0; j < width(); j++) {
            unsigned char *p = &_texture->pixels[(width() * i + j) * 4];
            p[0] = c.r;
            p[1] = c.g;
            p[2] = c.b;
        }
    }
    glBindTexture(GL_TEXTURE_2D, _texture->index);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, _texture->pixels);
}

void Background::createPhysics()
{
        const int hw = 10;
        const double sc = scale();
    createBox(0, height() / 2 / sc + hw, width() / 2 / sc, hw);
    createBox(0, -height() / 2 / sc - hw, width() / 2 / sc, hw);
    createBox(-width() / 2 / sc - hw, 0, hw, height() / 2 / sc);
    createBox(width() / 2 / sc + hw, 0, hw, height() / 2 / sc);
}

void Background::createBox(int x, int y, int hWidth, int hHeight)
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(x, y);

    b2PolygonShape box;
    box.SetAsBox(hWidth, hHeight);

    b2Body *body = world()->CreateBody(&bodyDef);
    body->CreateFixture(&box, 0);
}

void Background::draw()
{
    program.use();
    program.enableAttributes(vertexData);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, _texture->index);
    glUniform1i(glGetUniformLocation(program.index(), "u_background"), 0);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Background::update(int dt)
{
    time += dt;

    if(!changeColor) {
        const int colorTime = 3000;
        if(time > colorTime) {
            time = 0;
            changeColor = true;
        }
        return;
    }

    const int changeTime = 2000;
    if(time > changeTime) {
        time = 0;
        changeColor = false;
        colors.change();
        fill(colors.current());
        return;
    }

    double k2 = time / double(changeTime);
    double k1 = 1 - k2;

    const ColorPair &c = colors.current();
    const ColorPair &n = colors.next();

    Color a(c.a.r * k1 + n.a.r * k2, c.a.g * k1 + n.a.g * k2, c.a.b * k1 + n.a.b * k2);
    Color b(c.b.r * k1 + n.b.r * k2, c.b.g * k1 + n.b.g * k2, c.b.b * k1 + n.b.b * k2);

    fill({a, b});
}

Texture Background::texture() const
{
    return *_texture;
}
