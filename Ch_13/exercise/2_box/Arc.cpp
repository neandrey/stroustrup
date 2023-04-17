#include "Arc.h"

namespace Graph_lib{

    //Конструктор
    Arc::Arc(Point p, int r, int r_beg, int r_end) : Circle(p, r), rr_beg{r_beg}, rr_end{r_end}
    {}

    //функция рисования
    void Arc::draw_lines() const
    {
        if (color().visibility())
            fl_arc(point(0).x, point(0).y, 2 * radius(), 2 * radius(), r_beg(), r_end());
    }
}