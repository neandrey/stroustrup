#include "../../GUI/Simple_window.h"
#include "Arc.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;

    Point x{100, 100};
    Simple_window win(x, 600, 400, "Arc_draw");

    //240 градусов
    Arc a1{Point(100, 100), 70, 90, 180};
    //180 градусов
    Arc a2{Point{150, 150}, 70, 90, 240};
    //360 градусов
    Arc a3{Point{200, 200}, 70, 90, 360};

    //color
    a1.set_color(Color::green);
    a2.set_color(Color::red);
    a3.set_color(Color::yellow);

    //mark
    Mark m1{Point(100, 100), 'a'};
    Mark m2{Point(150, 150), 'b'};
    Mark m3{Point{200, 200}, 'c'};

    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);
    win.wait_for_button();
}
