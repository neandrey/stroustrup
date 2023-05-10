//шаблонный класс вектор. 
#include "std_lib_facilities.h" 

struct out_of_range{/*...*/}; //выход за пределы диапазона


template<typename T, typename A = allocator<T>> class My_vector{
    A alloc;
    int sz;
    T* elem;
    int space; //количество элементов + свободное место
public:
//Конструктор
    My_vector() : sz{0}, elem{nullptr}, space{0}
    {}
    explicit My_vector(int s) 
    : sz{s}, 
    elem{new T[s]},
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
    int capacity() const;                       //вывод доступной памяти vector

    T& at(int n);                               //доступ с проверкой
    const T& at(int n) const;

    T& operator[](int n){ return elem[n]; }     //доступ без проверки
    const T& operator[](int n) const { return elem[n]; }

    void reserve(int newalloc);                 //добавление памяти для новых элементов.
    void resize(int newsize, T val=T());        //создаем вектор нового размера
    void push_back(const T& d);                 //увеличивает размер вектора
};
template<typename T, typename A>
My_vector<T, A>::My_vector(const My_vector<T, A>& arg)
: sz{arg.sz}, elem{new T[arg.sz]}
{
    copy(arg.elem, arg.elem + arg.sz, elem);
}
template<typename T, typename A>
My_vector<T, A>& My_vector<T, A>::operator=(const My_vector<T, A>& a){

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

template<typename T, typename A>
My_vector<T, A>::My_vector(My_vector<T, A>&& a)
: sz{a.sz}, elem{a.elem}
{
    a.sz = 0;
    a.elem = nullptr;
}

template<typename T, typename A>
My_vector<T, A>& My_vector<T, A>::operator=(My_vector<T, A>&& a){

    delete[] elem;
    elem = a.elem;
    sz = a.sz;
    a.elem = nullptr;
    a.sz = 0;
    return *this;
}

template<typename T, typename A>
void My_vector<T, A>::reserve(int newalloc){

    if(newalloc <= space) return;
    T* p = alloc.allocate(newalloc); //выделяем новую память
    for(int i=0; i<sz; ++i)
        alloc.construct(&p[i], elem[i]);
    //уничтожаем 
    for(int i = 0; i < sz; ++i) alloc.destroy(&elem[i]);
    alloc.deallocate(elem, space);
    space = newalloc;
    elem = p;
    space = newalloc;
}

template<typename T, typename A>
int My_vector<T, A>::capacity() const{
    return space;
}

template <typename T, typename A>
T &My_vector<T, A>::at(int n)
{
   if(n < 0 || sz <= n) throw ::out_of_range();
   return elem[n]; 
}

template<typename T, typename A>
void My_vector<T,A>::resize(int newsize, T val){

    reserve(newsize);
    //создание
    for(int i = sz; i < newsize; ++i) alloc.construct(&elem[i], val);
    //уничтожение
    for(int i = newsize; i < sz; ++i) alloc.destroy(&elem[i]);
    sz = newsize;
}

template<typename T, typename A>
void My_vector<T, A>::push_back(const T& val){
    
    if(space == 0)
        reserve(8);
    else if (sz == space)
        reserve(2*space);
    alloc.construct(&elem[sz], val);
    ++sz;
}
//------------------------------------------------
void print_vec(My_vector<double>& v){

    for(size_t i = 0; i != v.size(); ++i)
        cout << v[i] << ' ';
}

void print_some(My_vector<int>& v){

    int i = -1;
    while (cin >> i && i != -1)
    try{
        cout << "v[" << i << "]==" << v.at(i) << endl;
    }
    catch(::out_of_range){
        cout << "Неверный индекс: " << i << "\n";
    }
}
//------------------------------------------------
int main(){
    My_vector<double> vec(1), vec1;

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

    My_vector<int> vec2;
    for(int i = 0; i != 3; ++i)
        vec2.push_back(i);

    print_some(vec2);


    return 0;
}
