#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 400, 400, "My window");

    //инициалы высотой 50px
    //инициал А
    Line la_1{Point{60, 10}, Point{60, 60}};
    Line la_2{Point{60, 10}, Point{10, 60}};
    Line la_3{Point{60, 35}, Point{35, 35}};

    //инициал С
    Line lb_1{Point{70, 10}, Point{70, 60}};
    Line lb_2{Point{70, 10}, Point{110, 10}};
    Line lb_3{Point{70, 60}, Point{110, 60}};

    //подчеркивание
    Line lc_1{Point{10, 70}, Point{110, 70}};

    //заполнение цветом
    la_1.set_color(Color::blue);
    la_2.set_color(Color::blue);
    la_3.set_color(Color::blue);

    lb_1.set_color(Color::dark_green);
    lb_2.set_color(Color::dark_green);
    lb_3.set_color(Color::dark_green);

    la_1.set_style(Line_style(Line_style::solid ,3));
    la_2.set_style(Line_style(Line_style::solid, 3));
    la_3.set_style(Line_style(Line_style::solid, 3));

    lb_1.set_style(Line_style(Line_style::solid ,3));
    lb_2.set_style(Line_style(Line_style::solid, 3));
    lb_3.set_style(Line_style(Line_style::solid, 3));

    lc_1.set_color(Color::red);
    lc_1.set_style(Line_style(Line_style::solid, 3));
   
    win.attach(la_1); 
    win.attach(la_2);
    win.attach(la_3);
    win.attach(lb_1);
    win.attach(lb_2);
    win.attach(lb_3);
    win.attach(lc_1);

    win.wait_for_button();
}
