#include "Box.h"

namespace Graph_lib{

    //Конструктор
    Box::Box(Point p, int w, int h, int r) 
    {
        //Рисуем линии
        l1.add(Point{p.x + r, p.y}, Point{p.x + w - r, p.y});
        l2.add(Point{p.x + w, p.y + r}, Point{p.x + w, p.y + h - r});
        l3.add(Point{p.x + w - r, p.y + h}, Point{p.x + r, p.y + h});
        l4.add(Point{p.x, p.y + h - r}, Point{p.x, p.y + r});

        //Рисуем закругления
        v_arc.push_back(new Arc{Point{p.x + r, p.y + r}, r, 90, 180});
        v_arc.push_back(new Arc{Point{p.x + w - r, p.y + r}, r, 90, 0});
        v_arc.push_back(new Arc{Point{p.x + w - r, p.y + h - r}, r, 0, -90});
        v_arc.push_back(new Arc{Point{p.x + r, p.y + h - r}, r, 180, 270});
    }

    //функция рисования
    void Box::draw_lines() const
    {
        l1.draw_lines();
        l2.draw_lines();
        l3.draw_lines();
        l4.draw_lines();

        for(int i = 0; i < v_arc.size(); ++i)
            v_arc[i].draw_lines();
    }
    
}
