//считываем символы в переменную string. 
#include "std_lib_facilities.h" 

class My_vector{
    int sz;
    double* elem;
public:
//Конструктор
    explicit My_vector(int s) 
    : sz{s},
    elem{new double[s]}
    {
        for(int i = 0; i < sz; ++i)
            elem[i] = 0.0;
    }
//Конструктор со списком инициализации
    My_vector(initializer_list<double> lst)
    : sz{lst.size()},
    elem{new double[sz]}
    {
        copy(lst.begin(), lst.end(), elem);
    }
//Копирующий конструктор
    My_vector(const My_vector& arg);
//Копирующее присваивание
    My_vector& operator=(const My_vector&);
//Перемещающий конструктор
    My_vector(My_vector&& a);
    My_vector& operator=(My_vector&&);

//Деструктор
    ~My_vector()
    { delete[] elem; }

//Свойства
    int size() const { return sz; }
    double get(int n) const { return elem[n]; }
    void set(int n, double v) { elem[n] = v; }
};

My_vector::My_vector(const My_vector& arg)
: sz{arg.sz}, elem{new double[arg.sz]}
{
    copy(arg.elem, arg.elem + arg.sz, elem);
}

My_vector& My_vector::operator=(const My_vector& a){

    double* p = new double[a.sz];
    copy(a.elem, a.elem + a.sz, p);
    delete[] elem;
    elem = p;
    sz = a.sz;
    return *this;
}

My_vector::My_vector(My_vector&& a)
: sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

My_vector& My_vector::operator=(My_vector&& a){

    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

//--------------------------------------------------
void f(int n){
    My_vector v(3);
    v.set(2, 2.2);
    My_vector v2{v};
    
    v.set(1, 99);
    v2.set(0, 88);
    cout << v.get(0) << ' ' << v2.get(1) << endl;

}
//------------------------------------------------
void f2(int n){
    
    My_vector v(3);
    v.set(2, 2.2);
    My_vector v2(4);
    v2 = v;

    cout << v2.get(2) << endl;

}
//------------------------------------------------
int main(){

    f(1);
    f2(2);

    My_vector v0(10);

    
    return 0;
}
