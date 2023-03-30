#ifndef POINT_H
#define POINT_H
#include "std_lib_facilities.h"

namespace my_point{

class Point{
public:
    friend ostream &operator<<(ostream &os, const Point &p);
    friend istream &operator>>(istream &is, Point &p);
    class Invalid{};
    Point();
    Point(int x, int y);
    Point get_point() const;
    int get_x() const { return x; }
    int get_y() const { return y; }

private:
    void set_point(int x, int y);
    void set_x(int xx) { x = xx; }
    void set_y(int yy) { y = yy; }
    int x;
    int y;
};

bool is_correct(int x, int y);
ostream &operator<<(ostream &os, const Point &p);
istream &operator>>(istream &is, Point &p);

}

#endif