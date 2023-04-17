#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


   Point x{100, 100};

    Simple_window win(x, 600, 400, "Mark");

    Circle c1{Point{100, 200}, 50};
    Circle c2{Point{150, 200}, 100};
    Circle c3{Point{200, 200}, 150};

    Mark m1{Point{100, 200}, 'x'};
    Mark m2{Point{150, 200}, 'y'};
    Mark m3{Point{200, 200}, 'z'};

    c1.set_color(Color::blue);
    c2.set_color(Color::red);
    c3.set_color(Color::green);

    win.attach(c1); 
    win.attach(c2);
    win.attach(c3);
    win.attach(m1);
    win.attach(m2);
    win.attach(m3);

    win.wait_for_button();
}
