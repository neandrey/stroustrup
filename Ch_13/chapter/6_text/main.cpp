#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Text");

    Text t(Point(200, 200), "A closed polyline that isn't a polygon");
    t.set_color(Color::blue);

    win.attach(t); 
    win.wait_for_button();
}
