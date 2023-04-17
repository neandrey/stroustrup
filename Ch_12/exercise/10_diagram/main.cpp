#include "../GUI/Simple_window.h"
#include "../GUI/Graph.h"

int main()
{
    using namespace Graph_lib;

    Point t1 {100, 100};
    Simple_window win(t1, 600, 400, "Diagram");

    int rect_x = 120;       //длина прямоугольника
    int rect_y = 50;        //ширина прямоугольника
    int retreat_x = 20;     //отступ от края по x
    int retreat_y = 40;     //отступ от края по y
    int between = 100;      //расст. между элементами
    int ret_text = 10;      //отступ для текста

    //Point.h
    Rectangle rPoint{Point{retreat_x, retreat_y}, rect_x, rect_y}; 
    Text tPoint{Point{retreat_x, retreat_y-ret_text}, "Point.h:"};
    
    //Graph.h
    int ret_graph_y = retreat_y + between;
    Rectangle rGraph{Point{retreat_x, ret_graph_y}, rect_x, rect_y};
    Text tGraph{Point{retreat_x, ret_graph_y-ret_text}, "Graph.h:"};

    //Линии
    int mid_rect = retreat_x + (rect_x / 2);
    Line l_point_graph{Point{mid_rect, retreat_y + rect_y}, Point{mid_rect, ret_graph_y}};
    

    //добавление к окну
    win.attach(tPoint);
    win.attach(tGraph);
    win.attach(rPoint);
    win.attach(rGraph);
    win.attach(l_point_graph);

    win.wait_for_button();

}
