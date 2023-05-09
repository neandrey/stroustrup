//считываем символы в переменную string. 
#include "std_lib_facilities.h" 

class My_vector{
    int sz;
    double* elem;
    int space; //количество элементов + свободное место
public:
//Конструктор
    My_vector() : sz{0}, elem{nullptr}, space{0}
    {}
    explicit My_vector(int s) 
    : sz{s}, 
    elem{new double[s]},
    space{s}
    {
        for(int i = 0; i < sz; ++i)
            elem[i] = 0.0;
    }

//Копирующий конструктор и присвоение
    My_vector(const My_vector& arg);
    My_vector& operator=(const My_vector&);

//Перемещающий конструктор и присваивание
    My_vector(My_vector&& a);
    My_vector& operator=(My_vector&&);

//Деструктор
    ~My_vector()
    { delete[] elem; }

//Свойства
    int size() const { return sz; }
    int capacity() const;           //вывод доступной памяти vector

    double& operator[](int n){ return elem[n]; }
    double operator[](int n) const{ return elem[n]; }

    void reserve(int newalloc);     //добавление памяти для новых элементов.
    void resize(int newsize);       //создаем вектор нового размера
    void push_back(double d);       //увеличивает размер вектора
};

My_vector::My_vector(const My_vector& arg)
: sz{arg.sz}, elem{new double[arg.sz]}
{
    copy(arg.elem, arg.elem + arg.sz, elem);
}

My_vector& My_vector::operator=(const My_vector& a){

    if(this == &a) return *this;

    if(a.sz <= space){
        for(int i = 0; i < a.sz; ++i)
            elem[i] = a.elem[i];
        sz = a.sz;
        return *this;
    }

    double *p = new double[a.sz];
    for(int i = 0; i < a.sz; ++i)
        p[i] = a.elem[i];
    delete[] elem;
    space = sz = a.sz;
    elem = p;
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

void My_vector::reserve(int newalloc){

    if(newalloc <= space) return;
    double* p = new double[newalloc];
    for(int i=0; i<sz; ++i)
        p[i] = elem[i];
    delete[] elem;
    elem = p;
    space = newalloc;
}

int My_vector::capacity() const{
    return space;
}

void My_vector::resize(int newsize){

    reserve(newsize);
    for(int i = sz; i < newsize; ++i)
        elem[i] = 0;
    sz = newsize;
}

void My_vector::push_back(double d){
    
    if(space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2*space);
    elem[sz] = d;
    ++sz;
}
//------------------------------------------------
void print_vec(My_vector& v){

    for(size_t i = 0; i != v.size(); ++i)
        cout << v[i] << ' ';
}
//------------------------------------------------
int main(){
    My_vector vec(1), vec1;

    cout << vec.capacity() << endl;

    for(int i = 1; i < 10; ++i)
        vec.push_back(i);

    print_vec(vec);
    cout << endl;

    cout << vec.capacity() << endl; 

    vec1 = vec;

    print_vec(vec1);
    cout << endl;

    cout << vec1.capacity() << endl;

    return 0;
}
