#ifndef BOX_H
#define BOX_H
#include "Arc.h"
#include "../../GUI/Graph.h"

namespace Graph_lib{
struct Box: Shape{
    Box(Point p, int w, int h, int r);
    void draw_lines() const;

private:
    Lines l1, l2, l3, l4;
    Vector_ref<Arc> v_arc; 
};
}

#endif 