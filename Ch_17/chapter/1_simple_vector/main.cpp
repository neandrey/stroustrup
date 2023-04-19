//указатели
#include "std_lib_facilities.h" 

//Очень упрощенный вектор double
class My_vector{
private:
    int sz;
    double* elem;
public:
    My_vector(int s) : sz{s}, elem{new double[s]}
    {
        for(int i = 0; i < s; ++i)
            elem[i] = 0;
    }
    ~My_vector()
    { delete[] elem;}

    int size() const { return sz; }
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
};
//---------------------------------------------------------
int main(){

    My_vector v(5);
    for(int i = 0; i < v.size(); ++i){
        v.set(i, 1.1*i);
        cout << "v[" << i << "]==" << v.get(i) << '\n';
    }

    return 0;
}

