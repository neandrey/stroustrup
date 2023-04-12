#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"
#include "../GUI/std_lib_facilities.h"

int main()
{
    using namespace Graph_lib;


    Point x{100, 100};

    Simple_window win(x, 600, 400, "Polyline");

    Vector_ref<Rectangle> vr;
    
    for(int i = 0; i < 16; ++i)
        for(int j = 0; j < 16; ++j){
            vr.push_back(new Rectangle{Point{i*20, j*20}, 20, 20});
            vr[vr.size()-1].set_fill_color(Color{i*16+j});
            win.attach(vr[vr.size()-1]);
        }

   
    win.wait_for_button();
}
