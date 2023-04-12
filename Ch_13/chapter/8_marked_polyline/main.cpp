#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Text");

    Marked_polyline mpl {"1234"};

    mpl.add(Point{100, 100});
    mpl.add(Point{150, 200});
    mpl.add(Point{250, 250});
    mpl.add(Point{300, 200});

    Marks pp{"x", {{100, 200}, {150, 300}, {250, 350}, {300, 300}}};


    win.attach(mpl);
    win.attach(pp);
    win.wait_for_button();
}
