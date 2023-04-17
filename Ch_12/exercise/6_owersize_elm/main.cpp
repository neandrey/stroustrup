#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 400, 300, "first_window");

    //Прямоугольник который не помещается в окно.
    Rectangle r1{Point{100, 100}, 500, 100};
   
    win.attach(r1);
    win.wait_for_button();

}
