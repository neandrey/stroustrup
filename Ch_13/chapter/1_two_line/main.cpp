#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Two lines");
     
    //Рисуем две линии
    // Line horizontal{x, Point{200, 100}};
    // Line vertical{Point{150, 50}, Point{150, 150}};

    //c помощью калсса Lines
    Lines x_lines;
    x_lines.add(Point{100, 100}, Point{200, 100});
    x_lines.add(Point{150, 50}, Point{150, 150});


    // win.attach(horizontal);
    // win.attach(vertical);
    win.attach(x_lines);
    win.wait_for_button();
}
