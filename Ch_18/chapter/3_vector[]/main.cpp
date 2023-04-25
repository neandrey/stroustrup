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

    double& operator[](int n){
        return elem[n];
    }

    double operator[](int n) const{
        return elem[n];
    }
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
//------------------------------------------------
void f(const My_vector& cv){

    double d = cv[1];
    //cv[1] = 2.0; //error
}
//------------------------------------------------
void ff(const My_vector& cv, My_vector& v){
    
    double d = cv[1];
    //cv[1] = 2.0; //error
    d = v[1];
    v[1] = 2.0;
}

//------------------------------------------------
int main(){

    My_vector v(10);

    for(int i = 0; i < v.size(); ++i){
        v[i] = i;
        cout << v[i] << ' ';
    } 
    cout << endl;

    //f(v);

    ff(v, v);

    
    return 0;
}
