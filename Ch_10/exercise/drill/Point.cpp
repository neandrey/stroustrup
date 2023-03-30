#include "Point.h"

namespace my_point{

Point::Point() : x{0}, y{0}
{}

Point::Point(int xx, int yy) : x{xx}, y{yy}
{
    //if(!is_correct(x, y)) throw Invalid(); 
}

void Point::set_point(int x, int y){
    this->x = x;
    this->y = y;
}

Point Point::get_point() const {

    return Point(x, y);
}

ostream &operator<<(ostream &os, const Point &p){

    os << "x = " << p.get_x() << " y = " << p.get_y();
    return os;
}

istream &operator>>(istream &is, Point &p){

    int x, y;
    cout << "Введите x и y: ";
    is >> x >> y;
    if(!is) return is;

    p.set_x(x);
    p.set_y(y);

    return is; 

}


}


