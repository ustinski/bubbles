#include "bubblecontainer.h"
#include "program.h"
#include "app.h"
#include "bubble.h"
#include "background.h"

#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

namespace BubbleContainer
{
    Program *_program;

    vector<Bubble*> instances;

    const int _refractionScale = 2;


    void createProgram();
    void createBackgroundTexture();
}

void BubbleContainer::init()
{
    createProgram();
    createBackgroundTexture();
}

void BubbleContainer::createProgram()
{
    _program = new Program;
    stringstream vertex;
    vertex <<   "#version 100 \n"
                "precision mediump float;"
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
    fragment << "#version 100 \n"
                "precision mediump float;"
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
                "   int sc = " << _refractionScale << ";"
                ""
                "   vec4 refracted_background = vec4(0);"
                "   for(int i = 0; i < sc; i++) for(int j = 0; j < sc; j++) {"
                "       vec2 pos = v_position + vec2(j, i) / float(sc);"
                "       float k_from_map = draw_refraction(pos).r;"
                "       float k = ((n - 1.0) * k_from_map + 1.0) / n;"
                "       vec2 texcoord = (pos * k + u_position) / vec2(" << App::width() << ", " << App::height() << ") + vec2(0.5);"
                "       refracted_background += texture2D(u_background, texcoord);"
                "   }"
                ""
                "   refracted_background /= float(sc * sc);"
                "   vec4 outline = draw_outline();"
                ""
                "   gl_FragColor = vec4(refracted_background.rgb * (1.0 - outline.a) + outline.rgb * outline.a, 1.0);"
                "}";
    _program->setShaders(vertex, fragment);

    _program->addAttribute("a_position", 2, 2, 0);
}

void BubbleContainer::createBackgroundTexture()
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, App::background().texture().index);
    glUniform1i(glGetUniformLocation(_program->index(), "u_background"), 0);
}

void BubbleContainer::add()
{
    const int min = App::height() < App::width() ? App::height() : App::width();
    const int marg = 5;
    int r, x, y;
    for(;;) {
        r = (min / 4 + rand() % (min / 2)) / 2;
        x = r + marg + rand() % (App::width() - 2 * (r + marg)) - App::width() / 2;
        y = r + marg + rand() % (App::height() - 2 * (r + marg)) - App::height() / 2;

        int i;
        for(i = 0; i < instances.size(); i++) if((instances[i]->position() - Vector(x, y)).length() < instances[i]->radius() + r) break;
        if(i == instances.size()) break;
    }

    instances.push_back(new Bubble(r, {x, y}));
}

void BubbleContainer::draw()
{
    for(int i = 0; i < instances.size(); i++) instances[i]->draw();
}

void BubbleContainer::update()
{
    for(int i = 0; i < instances.size(); i++) instances[i]->update();
}

int BubbleContainer::refractionScale()
{
    return _refractionScale;
}

Program *BubbleContainer::program()
{
    return _program;
}
