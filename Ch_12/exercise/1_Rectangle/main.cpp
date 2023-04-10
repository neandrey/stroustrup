#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 400, "My window");

    //Прямоугольник
    Rectangle r{Point{200, 200}, 100, 50};

    //Полигон
    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});

    //заполнение цветом
    poly_rect.set_color(Color::red);
    poly_rect.set_style(Line_style(Line_style::dash, 2));
    r.set_color(Color::blue);
    r.set_style(Line_style(Line_style::dash, 2));
   
    win.attach(poly_rect);
    win.attach(r); 

    win.wait_for_button();
}
