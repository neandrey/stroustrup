#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 600, "Gamlet");

    Image img{Point{0, 0}, "../GUI/friend.jpeg"};
    Text txt{Point{150, 40}, "Гамлет"};

    txt.set_font_size(30);

    win.attach(img);
    win.attach(txt);

    win.wait_for_button();

}
