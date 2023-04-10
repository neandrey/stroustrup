#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;


    Point t1 {100, 100};
    Simple_window win(t1, 600, 600, "Canvas");

    Axis xa{Axis::x, Point(20, 300), 280, 10, "x axis"};
    //Axis::x - горизонтальная ось
    //Начало оси - 20, 300
    //Длина оси - 280
    //Число делений - 10
    //Метка оси - "x axis"


    win.attach(xa);
    win.set_label("Canvas #2");

    win.wait_for_button();
}
