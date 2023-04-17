#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Polygon");

    Polygon poly = {
        {100, 100}, {150, 200}, {250, 250}, {300, 200}
    };

    Rectangle rect00{Point{150, 100}, 200, 100};
    Rectangle rect11{Point{50, 50}, Point{250, 150}};
    Rectangle rect12{Point{50, 150}, Point{250, 250}};
    Rectangle rect21{Point{250, 50}, 200, 100};
    Rectangle rect22{Point{250, 150}, 200, 100};

    rect00.set_fill_color(Color::yellow);
    rect11.set_fill_color(Color::blue);
    rect12.set_fill_color(Color::red);
    rect21.set_fill_color(Color::green);

    //сдвиг прямоугольника rect11
    rect11.move(400, 0);
    rect11.set_fill_color(Color::white);
    win.set_label("rectangles 2");

    //перемещение слоев
    win.put_on_top(rect00);
    win.set_label("rectangels 3");

    //удаление границ прямоугольников
    rect00.set_color(Color::invisible);
    rect11.set_color(Color::invisible);
    rect12.set_color(Color::invisible);
    rect21.set_color(Color::invisible);
    rect22.set_color(Color::invisible);
    
    //win.attach(poly);
    win.attach(rect00);
    win.attach(rect11);
    win.attach(rect12);
    win.attach(rect21);
    win.attach(rect22);
    win.wait_for_button();
}
