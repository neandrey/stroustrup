//переполнение выделенной памяти из кучи. 
#include "std_lib_facilities.h" 

void size_double(); //размер типа double
size_t memory_size(int n); //сколько памяти выделено

int main(){

    size_t max = 10000;
    size_double();

    while(true){

        double* dd = new double[max];
        cout << "Количество выделенной памяти: " << memory_size(max) 
        << " байт" << endl;
    }

    return 0;
}

void size_double()
//сколько памяти занимает double
{
    cout << "размер типа double в байтах = " << sizeof(double) << endl;
}

size_t memory_size(int n)
//количество выделенной памяти
{
    static size_t res{0};
    res += sizeof(double) * n;

    return res;
}
