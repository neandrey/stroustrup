#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 400, 300, "tic tac pole");

    //Прямоугольник
    Rectangle r11{Point{0, 0}, 100, 100};
    Rectangle r12{Point{100, 0}, 100, 100};
    Rectangle r13{Point{200, 0}, 100, 100};

    Rectangle r21{Point{0, 100}, 100, 100};
    Rectangle r22{Point(100, 100), 100, 100};
    Rectangle r23{Point{200, 100}, 100, 100};

    Rectangle r31{Point{0, 200}, 100, 100};
    Rectangle r32{Point{100, 200}, 100, 100};
    Rectangle r33{Point{200, 200}, 100, 100};

    //заполнение цветом
    r11.set_fill_color(Color::red);
    r12.set_fill_color(Color::white);
    r13.set_fill_color(Color::red);

    r21.set_fill_color(Color::white);
    r22.set_fill_color(Color::red);
    r23.set_fill_color(Color::white);

    r31.set_fill_color(Color::red);
    r32.set_fill_color(Color::white);
    r33.set_fill_color(Color::red);
   
    //добавление к окну
    win.attach(r11); 
    win.attach(r12);
    win.attach(r13);
    win.attach(r21);
    win.attach(r22);
    win.attach(r23);
    win.attach(r31);
    win.attach(r32);
    win.attach(r33);
    win.wait_for_button();

}
