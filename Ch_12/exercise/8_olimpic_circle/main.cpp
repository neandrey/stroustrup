#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 400, "Olimpic circle");

    Rectangle r{Point{0, 0}, Point{450, 250}};

    //Circle c1{};
    Circle c1{Point{100, 100}, 50};
    Circle c2{Point{220, 100,}, 50};
    Circle c3{Point{340, 100}, 50};

    Circle c4{Point{160, 150}, 50};
    Circle c5{Point{280, 150}, 50};

    //line_style
    c1.set_style(Line_style(Line_style::solid, 6));
    c2.set_style(Line_style(Line_style::solid, 6));
    c3.set_style(Line_style(Line_style::solid, 6));
    c4.set_style(Line_style(Line_style::solid, 6));
    c5.set_style(Line_style(Line_style::solid, 6));

    //Color
    c1.set_color(Color::blue);
    c2.set_color(Color::black);
    c3.set_color(Color::red);
    c4.set_color(Color::yellow);
    c5.set_color(Color::green);
    r.set_fill_color(Color::white);

    win.attach(r);
    win.attach(c1);
    win.attach(c2);
    win.attach(c3);
    win.attach(c4);
    win.attach(c5);
    win.wait_for_button();

}
