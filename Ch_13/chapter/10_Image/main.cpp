#include "../../GUI/Simple_window.h"
#include "../../GUI/Graph.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Image_Rita");

    Image rita {Point{0,0}, "../../GUI/rita.jpg"};
    Image path {Point{0,0}, "../../GUI/rita_path.gif"}; 

    path.set_mask(Point{50, 250}, 600, 400);

    win.attach(path);
    win.attach(rita);

    win.wait_for_button();
}
