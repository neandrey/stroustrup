#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Polyline");

    Open_polyline opl = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };

    Closed_polyline cpl = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };
    
    win.attach(opl);
    win.attach(cpl);
    win.wait_for_button();
    
}
