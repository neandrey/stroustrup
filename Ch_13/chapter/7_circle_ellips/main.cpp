#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Text");

    Circle c1{Point{100, 200}, 50};
    Circle c2{Point{150, 200}, 100};
    Circle c3{Point{200, 200}, 150};

    Ellipse e1{Point{450, 200}, 50, 50};
    Ellipse e2{Point{450, 200}, 100, 50};
    Ellipse e3{Point{450, 200}, 100, 150};

    win.attach(c1); 
    win.attach(c2);
    win.attach(c3);

    win.attach(e1);
    win.attach(e2);
    win.attach(e3);
    win.wait_for_button();
}
