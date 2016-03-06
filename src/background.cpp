#include "background.h"
#include "app.h"
#include "matrix.h"
#include "color.h"

#include <iostream>
#include <sstream>

using namespace std;

Background::Background() : time(0), changeColor(false)
{
    GLfloat w = App::width() / 2;
    GLfloat h = App::height() / 2;

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
}

void Background::createProgram()
{
    program = new Program();
    
    stringstream vertex;
    vertex <<   "precision mediump float;"
                ""
                "uniform mat4 mvp;"
                ""
                "attribute vec2 a_position;"
                ""
                "varying vec2 v_position;"
                ""
                "void main()"
                "{"
                ""
                "    gl_Position = mvp * vec4(a_position, 0, 1);"
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
                "    gl_FragColor = texture2D(u_background, vec2(v_position.x / " << App::width() << ".0, v_position.y / " << App::height() << ".0) + vec2(0.5));"
                "}";
    program->setShaders(vertex, fragment);

    program->addAttribute("a_position", 2, 2, 0);
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
    unsigned char *pixels = new unsigned char[App::height() * App::width() * 4];
    for(int i = 0; i < App::height(); i++) {
        for(int j = 0; j < App::width(); j++)
            pixels[(App::width() * i + j) * 4 + 3] = 255;
    }
    background = new Texture(0, program, "u_background", App::width(), App::height(), pixels);
    fill(colors.current());
}

void Background::fill(const ColorPair &pair)
{
    for(int i = 0; i < App::height(); i++) {
        const int lineSize = 32;
        const Color &c = i % (lineSize * 2) > lineSize ? pair.a : pair.b;
        for(int j = 0; j < App::width(); j++) {
            unsigned char *p = &background->pixels[(App::width() * i + j) * 4];
            p[0] = c.r;
            p[1] = c.g;
            p[2] = c.b;
        }
    }
    glBindTexture(GL_TEXTURE_2D, background->index);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, App::width(), App::height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, background->pixels);
}

void Background::draw()
{
    program->use();
    program->enableAttributes(vertexData);

    GLuint mvp = glGetUniformLocation(program->index(), "mvp");
    glUniformMatrix4fv(mvp, 1, GL_FALSE, App::projection().data());

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, background->index);
    glUniform1i(glGetUniformLocation(program->index(), "u_background"), 0);

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
