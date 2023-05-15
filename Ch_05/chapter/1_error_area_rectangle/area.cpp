#include "std_lib_facilities.h"


class Bad_area {};
//Площадь прямоугольника
int area(int length, int width){
    if(length<=0 || width <=0)
        throw Bad_area{}; 
    return length * width;
}
//Площадь в пределах рамки
int framed_area(int x, int y){
    return area(x-2, y-2);
}
//-------------------------------------
int main(int argc, char const *argv[])
{
    try {
        int x = -1;
        int y = 2;
        int z = 4;

        int area1 = area(x, y);
        int area2 = framed_area(1, z);
        int area3 = framed_area(y, z);
        double ratio = double(area1) / area3;
    }catch(Bad_area) {
        cout << "Неверный аргумент функции area()\n";
    }
    
    return 0;
}
