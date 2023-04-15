#include "Arc.h"

namespace Graph_lib{

    //Конструктор
    Arc::Arc(Point p, int w, int h, int d) : Ellipse(p, w, h), d{d}
    {}

    //функция рисования
    void Arc::draw_lines() const
    {
        if (color().visibility())
            fl_arc(point(0).x, point(0).y, 2 * major(), 2 * minor(), 0, get_d());
    }
}