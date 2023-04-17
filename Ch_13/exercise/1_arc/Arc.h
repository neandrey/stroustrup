#ifndef ARC_H
#define ARC_H
#include "../../GUI/Graph.h"

namespace Graph_lib{

struct Arc : Ellipse{
    Arc(Point p, int w, int h, int d);
    void draw_lines() const;

    int get_d() const {return d;}
    void set_d(int dd) {d = dd;}

private:
    int d;
};

}

#endif 