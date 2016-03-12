#ifndef BUBBLECONTAINER_H
#define BUBBLECONTAINER_H

class Program;

namespace BubbleContainer
{
    void init();

    void add();
    void draw();
    void update();

    int refractionScale();
    Program *program();
}

#endif // BUBBLECONTAINER_H
