#include "../../GUI/Simple_window.h"
#include "Box.h"
#include "../../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;

    Point x{100, 100};
    Simple_window win(x, 600, 400, "Box_draw");

    Vector_ref<Box> v_box;
    int radius = 20;

    for(int h = 40, j = 40; j < 200 or h < 200; j+=20, h+=20)
        v_box.push_back(new Box{Point{j, h}, j, h, radius}); 

    for(int i = 0; i < v_box.size(); ++i)
        win.attach(v_box[i]);

    //Box b{Point(10, 10), 200, 200, 20};

    //win.attach(v_box); 
    win.wait_for_button();
}
