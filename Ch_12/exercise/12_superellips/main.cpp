#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 600, "SuperEllips");

    Ellipse el{Point{10, 20}, 15, 40};

    win.attach(el);
    win.wait_for_button();

}
