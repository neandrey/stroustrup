#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 300, 300, "My window");

    //Прямоугольник
    Rectangle r{Point{0, 0}, 100, 30};

    //Текст
    Text t{Point{10, 15}, "Howdy!"};

    //заполнение цветом
    r.set_color(Color::blue);
    r.set_style(Line_style(Line_style::dash, 2));
   
    win.attach(r); 
    win.attach(t);

    win.wait_for_button();
}
