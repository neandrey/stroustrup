#include "std_lib_facilities.h"

char ask_user(string question){

    cout << question << "? (введите y или n)\n";
    string answer = "";
    cin >> answer;
    if(answer == "y" || answer == "yes") return 'y';
    if(answer == "n" || answer == "no") return 'n';
    return 'b';
}

//вычисляем площадь прямоугольника
//возвращаем -1, если аргумент некорретен
int area(int length, int width){

    if(length <= 0 or width <= 0) return -1;
    return length * width;
}