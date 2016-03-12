#include "bubble.h"
#include "app.h"
#include "background.h"
#include "bubblecontainer.h"

#include <iostream>
#include <sstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

Bubble::Bubble(GLfloat r, Vector position)
{
    _r = r;
    _position = position;
    const int speed = 500;
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
    createPhysics();
}

void Bubble::createRefractionMap()
{
    const int r_sc = _r * BubbleContainer::refractionScale();
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
    refractionMap = new Texture(1, BubbleContainer::program(), "u_refraction_map", imageWidth, imageWidth, pixels);
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

    outline = new Texture(2, BubbleContainer::program(), "u_outline", imageWidth, imageWidth, pixels);
}

void Bubble::createPhysics()
{
    b2BodyDef bodyDef;
    bodyDef.position.Set(_position.x() / App::scale(), _position.y() / App::scale());
    bodyDef.linearVelocity.Set(_speed.x() / App::scale(), _speed.y() / App::scale());
    bodyDef.type = b2_dynamicBody;
    _body = App::world()->CreateBody(&bodyDef);

    b2FixtureDef fixtureDef;
    {
        b2CircleShape *circleShape = new b2CircleShape;
        circleShape->m_p.Set(0, 0);
        circleShape->m_radius = _r / App::scale();
        fixtureDef.shape = circleShape;
    }

    fixtureDef.density = 1;
    fixtureDef.friction = 0;
    fixtureDef.restitution = 1;

    _body->CreateFixture(&fixtureDef);
}

void Bubble::draw()
{
    BubbleContainer::program()->use();
    BubbleContainer::program()->enableAttributes(vertexData);

    glUniform2fv(glGetUniformLocation(BubbleContainer::program()->index(), "u_position"), 1, _position.data());
    glUniform1i(glGetUniformLocation(BubbleContainer::program()->index(), "u_background"), 0);

    refractionMap->bind();
    glUniform1i(glGetUniformLocation(BubbleContainer::program()->index(), "u_refraction_map"), 1);

    glUniform1fv(glGetUniformLocation(BubbleContainer::program()->index(), "u_radius"), 1, &_r);

    outline->bind();
    glUniform1i(glGetUniformLocation(BubbleContainer::program()->index(), "u_outline"), 2);

    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void Bubble::update()
{
    _position = App::scale() * _body->GetPosition();
}
