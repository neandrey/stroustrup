//считываем символы в переменную string. 
#include "std_lib_facilities.h" 
//------------------------------------------------
void f(int n){
    char lac[20];

    int lai[60];
    double lad[n];
    
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

    double ad[10]{0,0,0,0,0,0,0,0,0,0};
    double* p = &ad[5];

    *p = 7;
    p[2] = 6;
    p[-3] = 9;

    for(double* p = &ad[0]; p < &ad[10]; ++p)
        cout << *p << ' ';
    cout << endl;

    char ch[3] = {'a', 'b', 'c'};

    cout << strlen(ch) << endl;
    
    return 0;
}
