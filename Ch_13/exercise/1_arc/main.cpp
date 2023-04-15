#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "Arc.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;

    Point x{100, 100};
    Simple_window win(x, 600, 400, "Arc_draw");

    //240 градусов
    Arc a1{Point(200, 200), 70, 70, 240};
    //180 градусов
    Arc a2{Point{300, 300}, 70, 70, 180};
    //360 градусов
    Arc a3{Point{100, 100}, 70, 70, 360};

    //color
    //mark

    win.attach(a1);
    win.attach(a2);
    win.attach(a3);
    win.wait_for_button();
}
