#ifndef BOX_H
#define BOX_H
#include "../GUI/Graph.h"

namespace Graph_lib{

struct Box: Shape{
    Box(Point p, int w, int h);

private:
    Point p;
    int w, h;
};
}

#endif 