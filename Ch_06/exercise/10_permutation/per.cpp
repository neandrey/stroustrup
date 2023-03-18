#include "std_lib_facilities.h"
/*
План пирложения:
ввод данных
-запросить 2 числа
-запросить перестановка или сочитание

обработка
-если перестановка - вычисляем перестановку
-если сочитание - вычисляем перестановку и делим на b!

Выводим результат
*/
int factorial(int val);
int permutation(int a, int b);
int combination(int a, int b);
int switch_value(char ch, int a, int b);
void corr_int_value(int a, int b);
//---------------------------------------
int main(int argc, char const *argv[])
{
    int a, b;
    char ch = 'a';

    cout << "Введите два целых числа: ";
        cin >> a >> b;
    if(!cin){
        error("Введены неверные значения не равно int");
    }
    corr_int_value(a, b);

    cout << "Перестановка или Сочетания (p или с): ";
    cin >> ch;
    if(!cin){
        error("Введен не символ char");
    }

    cout << switch_value(ch, a, b) << endl; 

    return 0;
}
//-------------------------------------------
int factorial(int val){
    int res = 1;

    for (size_t i = 0; i != val; ++i)
        res *= i+1;

    return res; 
}
//-------------------------------------------
int permutation(int a, int b)
{
    return factorial(a) / factorial(a - b);
}
//------------------------------------------
int combination(int a, int b)
{
   return permutation(a, b) / factorial(b); 
}
//-----------------------------------------
int switch_value(char ch, int a, int b)
{
    switch (ch)
    {
    case 'p':
        return permutation(a, b);
        break;
    case 'c':
        return combination(a, b);
        break;
    default:
        error("Не знаю такого символа");
        break;
    }
}
//---------------------------------------------
void corr_int_value(int a, int b)
{
    if(a < 0 or b < 0)
        error("числа должны быть больше нуля");
    if(a < b)
        error("1-oe число должно быть больше 2-го");
}
//--------------------------------------------
