//динамическое выделение памяти
#include "std_lib_facilities.h" 

double* calc(int res_size, int max);

int main(){

    double* p = new double[4];

    *p = 7.7;
    p[2] = 9.9;

    double x = *p;
    cout << "x[0] = " << x << endl;
    *p = 8.9;

    x = p[3];
    cout << "x[3] = " << x << endl;

    p[3] = 4.4;
    double y = p[0];
    cout << "y[0] = " << y << endl;

    for (int i = 0; i < 4; ++i)
        cout << p[i] << ' ';
    cout << endl;

    //инициализация веделенной памяти
    double* p2 = new double(5.5);
    double* p4 = new double[5] {0, 1, 2, 3, 4};
    //double* p5 = new double[] {0, 1, 2, 3, 4};

    //нулевой указатель
    double* p0 = nullptr;

    double* r = calc(1, 5);
    delete r;


    return 0;
}
double* calc(int res_size, int max){
    

    double* p = new double[max];
    double* res = new double[res_size];
    delete[] p;


    return res;
}
