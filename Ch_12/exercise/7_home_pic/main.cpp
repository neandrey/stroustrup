#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 400, "My home");

    //Прямоугольник
    Rectangle r{Point{250, 150}, 100, 100};
    Rectangle window1{Point{260, 170}, 20, 20};
    Rectangle window2{Point{320, 170}, 20, 20};
    Rectangle door{Point{280, 200}, 40, 50};
    Rectangle tube{Point{320, 100}, 20, 40};

    //Треугольник
    Polygon pl;
    pl.add(Point{250, 150});
    pl.add(Point{300, 100});
    pl.add(Point{350, 150});

    //заполнение цветом
    r.set_fill_color(Color::red);
    pl.set_fill_color(Color::red);
    window1.set_fill_color(Color::blue);
    window2.set_fill_color(Color::blue);
    door.set_fill_color(Color::dark_red);
    tube.set_fill_color(Color::red);

    //вниз
    //win.set_changed(tube);
   
    //добавление к окну
    win.attach(r); 
    win.attach(tube);
    win.attach(pl);
    win.attach(window1);
    win.attach(window2);
    win.attach(door);
    win.wait_for_button();

}
