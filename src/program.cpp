#include "program.h"
#include "app.h"

#include <stdlib.h>
#include <iostream>

Program::Program()
{
    _index = glCreateProgram();
}

void Program::setShaders(const GLchar *vertex, const GLchar *fragment)
{
    loadShader(GL_VERTEX_SHADER, vertex);
    loadShader(GL_FRAGMENT_SHADER, fragment);

    glLinkProgram(_index);
}

void Program::setShaders(const stringstream &vertex, const stringstream &fragment)
{
    setShaders(vertex.str().c_str(), fragment.str().c_str());
}

void Program::loadShader(GLenum type, const GLchar *shaderSrc)
{
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderSrc, 0);
    glCompileShader(shader);
//     GLint success = 0;
//     glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
//     if(success == GL_FALSE) {
//         GLint logSize = 0;
//         glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logSize);
//         vector<GLchar> errorLog(logSize);
//         glGetShaderInfoLog(shader, logSize, &logSize, &errorLog[0]);
//         cerr << errorLog.data() << '\n';
//         glDeleteShader(shader);
//         App::close();
//         exit(EXIT_FAILURE);
//     }

    glAttachShader(_index, shader);
}

void Program::addAttribute(const string &name, GLuint size, GLsizei stride, int offset)
{
    attributes.push_back({glGetAttribLocation(_index, name.c_str()), name, size, stride * sizeof(GL_FLOAT), offset * sizeof(GL_FLOAT)});
}

void Program::enableAttributes(const void *pointer)
{
    for(int i = 0; i < attributes.size(); i++) {
        const Attribute &a = attributes[i];
        glVertexAttribPointer(a.index, a.size, GL_FLOAT, GL_FALSE, a.stride, pointer + a.offset);
        glEnableVertexAttribArray(a.index);
    }
}
