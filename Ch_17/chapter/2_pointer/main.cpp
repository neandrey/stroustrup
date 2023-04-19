//указатели
#include "std_lib_facilities.h" 

void sizes(char ch, int I, int* pi);

int main(){

    int x = 17;
    int* pi = &x;

    double e = 2.71828;
    double* pd = &e;

    *pi = 27;
    *pd = 3.14159;
    *pd = *pi;

    cout << "pi == " << pi << "; cодержимое pi == " << *pi << "\n";
    cout << "pd == " << pd << "; содержимое pd == "  << *pd << "\n";

    char ch = 'a';
    int i = 1;
    int* ip = &i;

    sizes(ch, i, ip);

    //сколько памяти занимает вектор
    vector<int> v(1000);
    cout << "Размер vector<int>(1000) = " << sizeof(v) << endl;

    return 0;
}

void sizes(char ch, int I, int* pi){

    cout << "размер типа char равен " << sizeof(char) << ' '
        << sizeof(ch) << '\n';
    cout  << "размер типа int равен " << sizeof(int) << ' '
        << sizeof(I) << '\n';
    cout << "размер типа int* равен " << sizeof(int*) << ' '
        << sizeof(pi) << '\n';
}