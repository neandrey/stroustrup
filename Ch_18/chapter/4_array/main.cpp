//считываем символы в переменную string. 
#include "std_lib_facilities.h" 
//------------------------------------------------
void f(int n){
    char lac[20];
    
    int lai[60];
    //double lad[n]; размер массива не константа
}

void f2(){
    char lac[20]; //до выхода из области видимости
    lac[7] = 'a';
    *lac = 'b';
    //lac[-2] = 'b'; ??
    //lac[200] = 'c'; ??
}

int strlen(const char* p){
    int count = 0;
    while(*p){
        ++count; ++p;
    }
    return count;
}

int main(){
    const int max = 100;
    int gai[max];
    f(5); 
    f2();

    return 0;
}
