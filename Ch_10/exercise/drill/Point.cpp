#include "Point.h"

namespace my_point{

Point::Point() : x{0}, y{0}
{}
//--------------------------------------------------
Point::Point(int xx, int yy) : x{xx}, y{yy}
{}
//--------------------------------------------------
void Point::set_point(int x, int y){
    this->x = x;
    this->y = y;
}
//---------------------------------------------------
Point Point::get_point() const {

    return Point(x, y);
}
//---------------------------------------------------
ostream &operator<<(ostream &os, const Point &p)
{
    os << "(" << p.get_x() << ", " << p.get_y() << ")";
    return os;
}
//---------------------------------------------------
istream &operator>>(istream &is, Point &p){
    
    char ch1;
    if(is >> ch1 && ch1 != '('){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2, ch3;
    int x, y;
    is >> x >> ch2 >> y >> ch3;
    if(!is || ch3 != ')'){ 
        if(is.eof()) return is;
        error("Неправильный ввод");
    }

    p.set_x(x);
    p.set_y(y);

    return is; 
}
//---------------------------------------------------
bool operator==(const Point &p1, const Point &p2) {

    return (p1.get_x() == p2.get_x() and p1.get_y() == p2.get_y());
}
//----------------------------------------------
bool operator!=(const Point &p1, const Point &p2)
{
    return !(p1 == p2);
}
//----------------------------------------------------
}


