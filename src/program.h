#ifndef PROGRAM_H
#define PROGRAM_H

#include <GLES2/gl2.h>

#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct Attribute
{
    GLuint index;
    string name;
    GLuint size;
    GLsizei stride;
    int offset;
};

class Program
{
public:
    Program();

    void setShaders(const GLchar *vertex, const GLchar *fragment);
    void setShaders(const stringstream &vertex, const stringstream &fragment);
    void use();
    void addAttribute(const string &name, GLuint size, GLsizei stride, int offset);
    void enableAttributes(const void *pointer);
    GLuint index();

private:
    GLuint _index;
    vector<Attribute> attributes;


    void loadShader(GLenum type, const GLchar *shaderSrc);
};

#endif // PROGRAM_H
