#ifndef ARC_H
#define ARC_H
#include "../../GUI/Graph.h"

namespace Graph_lib{

struct Arc : Circle{
    Arc(Point p, int r, int r_beg, int r_end);
    void draw_lines() const;

    int r_beg() const {return rr_beg;}
    int r_end() const {return rr_end;}

private:
    int rr_beg, rr_end;
};

}

#endif 