#include "bubble.h"
#include "app.h"
#include "background.h"

#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

const int refractionScale = 2;

Program *Bubble::program;

void Bubble::initCommon()
{
    createProgram();
    createBackgroundTexture();
}

Bubble::Bubble(GLfloat r)
{
    _r = r;
    const int speed = 150;
    _speed.setValues(rand() % speed - speed / 2, rand() % speed - speed / 2);

    vertexData = new GLfloat[12] {
            -r, -r,
             r, -r,
             r,  r,
             r,  r,
            -r,  r,
            -r, -r
    };




    createRefractionMap();
    createOutline();
}

void Bubble::createProgram()
{
    program = new Program;
    stringstream vertex;
    vertex <<   "precision mediump float;"
                ""
                "uniform vec2 u_position;"
                ""
                "attribute vec2 a_position;"
                ""
                "varying vec2 v_position;"
                ""
                "void main()"
                "{"
                "   v_position = a_position;"
                ""
                "   gl_Position = vec4((u_position + a_position) * 2.0 / vec2(" << App::width() << ", " << App::height() << "), 0, 1);"
                "}";
    stringstream fragment;
    fragment << "precision mediump float;"
                ""
                "uniform vec2 u_position;"
                "uniform sampler2D u_background;"
                "uniform sampler2D u_refraction_map;"
                "uniform float u_radius;"
                "uniform sampler2D u_outline;"
                ""
                "varying vec2 v_position;"
                ""
                "vec4 draw_refraction(vec2 pos)"
                "{"
                "   return texture2D(u_refraction_map, pos / 2.0 / u_radius + vec2(0.5));"
                "}"
                ""
                "vec4 draw_outline()"
                "{"
                "   return texture2D(u_outline, v_position / 2.0 / u_radius + vec2(0.5));"
                "}"
                ""
                "void main()"
                "{"
                "   if(draw_refraction(v_position).a == 0.0) {"
                "       gl_FragColor = draw_outline();"
                "       return;"
                "   }"
                ""
                "   float n = 1.8;"
                "   int sc = " << refractionScale << ";"
                ""
                "   vec4 refracted_background = vec4(0);"
                "   for(int i = 0; i < sc; i++) for(int j = 0; j < sc; j++) {"
                "       vec2 pos = v_position + vec2(j, i) / float(sc);"
                "       float k_from_map = draw_refraction(pos).r;"
                "       float k = ((n - 1.f) * k_from_map + 1.f) / n;"
                "       vec2 texcoord = (pos * k + u_position) / " << App::background().textureSize() << ".0 + vec2(0.5);"
                "       refracted_background += texture2D(u_background, texcoord);"
                "   }"
                ""
                "   refracted_background /= float(sc * sc);"
                "   vec4 outline = draw_outline();"
                ""
                "   gl_FragColor = vec4(refracted_background.rgb * (1.0 - outline.a) + outline.rgb * outline.a, 1.0);"
                "}";
    program->setShaders(vertex, fragment);

    program->addAttribute("a_position", 2, 2, 0);
}

void Bubble::createBackgroundTexture()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, App::background().texture().index);
    glUniform1i(glGetUniformLocation(program->index(), "u_background"), 0);
}

void Bubble::createRefractionMap()
{
    const int r_sc = _r * refractionScale;
    const int imageWidth = r_sc * 2;
    unsigned char *pixels = new unsigned char[imageWidth * imageWidth * 4];
    for(int i = 0; i < imageWidth; i++) for(int j = 0; j < imageWidth; j++) {
        unsigned char *p = &pixels[(imageWidth * i + j) * 4];

        Vector rv(j + 0.5 - r_sc, i + 0.5 - r_sc);
        double rad = rv.length();
        if(rad > r_sc - 0.5) {
            for(int l = 0; l < 4; l++) p[l] = 0;
            continue;
        }

        double sinA = rad / r_sc;
        double A = asin(sinA);

        double n = 1.8;

        double sinB = sinA / n;
        double B = asin(sinB);

        double k = 1 - r_sc * cos(A) * tan(A - B) / rad;
        //transform k from {1/n, 1} to {0, 255}
        k = (n * k - 1) * 255 / (n - 1);

        for(int l = 0; l < 3; l++) p[l] = k;
        p[3] = 255;
    }
    refractionMap = new Texture(1, program, "u_refraction_map", imageWidth, imageWidth, pixels);
}

void Bubble::createOutline()
{
    //const int outlineScale = 2;
    const int imageWidth = _r * 2;
    unsigned char *pixels = new unsigned char[imageWidth * imageWidth * 4];
    for(int i = 0; i < imageWidth; i++) for(int j = 0; j < imageWidth; j++) {
        int alpha = 0;
        for(int k = 0; k < 2; k++) for(int l = 0; l < 2; l++) {
            Vector rv(j - _r + 0.25 + l * 0.5, i - _r + 0.25 + k * 0.5);
            double rr = rv.lengthSquare();
            const int outlineWidth = 2;
            const int rmin = _r - outlineWidth;
            if(rr >= rmin * rmin && rr <= _r * _r)
                alpha += 255;
        }
        unsigned char *p = &pixels[(i * imageWidth + j) * 4];
        for(int k = 0; k < 3; k++) p[k] = 255;
        p[3] = alpha / 4;
    }

    outline = new Texture(2, program, "u_outline", imageWidth, imageWidth, pixels);
}

void Bubble::draw()
{
    program->use();
    program->enableAttributes(vertexData);

    glUniform2fv(glGetUniformLocation(program->index(), "u_position"), 1, _position.data());
    glUniform1i(glGetUniformLocation(program->index(), "u_background"), 0);

    refractionMap->bind();
    glUniform1i(glGetUniformLocation(program->index(), "u_refraction_map"), 1);

    glUniform1fv(glGetUniformLocation(program->index(), "u_radius"), 1, &_r);

    outline->bind();
    glUniform1i(glGetUniformLocation(program->index(), "u_outline"), 2);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Bubble::update(int dt)
{
    _position += _speed * (double(dt) / 1000);
}
