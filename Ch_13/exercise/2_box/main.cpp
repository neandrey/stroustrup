#include "../GUI/Simple_window.h"
#include "Arc.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;

    Point x{100, 100};
    Simple_window win(x, 600, 400, "Arc_draw");

    
    win.wait_for_button();
}
