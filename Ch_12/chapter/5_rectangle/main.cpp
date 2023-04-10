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

    Axis ya{Axis::y, Point(20, 300), 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
    //sin() в диапазоне [0, 100) от (0, 0) до (20, 150)
    //Используя 1000 точек
    //50 для масштабирования координаты

    sine.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});

    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);

    Rectangle r{Point{200, 200}, 100, 50};
    //Прямоугольник верхний левый угол, ширина, высота

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});


    
    win.attach(poly_rect);
    win.attach(r); 
    win.attach(poly);
    win.attach(ya);
    win.attach(xa);
    win.attach(sine);
    win.set_label("Canvas #5");

    win.wait_for_button();
}
