#include "std_lib_facilities.h"

int area(int length, int width){
//площадь прямоугольника

    if(length <=0 or width <= 0)
        error("Неположительный аргумент area()");
    return length * width;
}

int framed_area(int x, int y){
//площадь в пределах рамки

    constexpr int frame_width = 2;
    if(x-frame_width <= 0 or y-frame_width <= 0)
        error("Неположительный аргумент функции area()"
        "при вызове из функции framed_area()");
    return area(x-frame_width, y-frame_width);
}

int main(){

    int x = -1;
    int y = 2;
    int z = 4;

    int area1 = area(x, y);
    int area2 = framed_area(1, z);
    int area3 = framed_area(y, z);
    double ratio = double(area1) / area3;

    cout << ratio << endl;

    return 0;
}