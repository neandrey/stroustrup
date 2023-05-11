//0_drill 
#include "std_lib_facilities.h" 
/*
1. - класс template<typename T> struct S{T val;};
2. - добавить конструктор
3. - определить переменные типов S<int>, S<char>, S<double>, S<string>, S<vector<int>>
4. - вывести значения на экран
5. - добавить функцию get()
6. - разместить get() за пределами класса
7. - сделайте val закрытым
8. - вывести значения через get()
9. - добавте функцию set()
10. - заменить set() на S<T>::operator=(const T&)
11. - константную и неконстантную get()
12. - функция read_val(T& v) для потока cin
13. - read_val(T& v) чтобы считать данные в каждую из переменных
14. - >> << для vector<T> использую формат {val, val, val} для функции read_val()
*/

template<typename T>
struct S{
public:
    //конструктор
    S() : val(T())
    {}
    S(T v) : val(v)
    {}
    //шаблонная функция get()
    T& get();
    const T& get() const;
    void set(const T&);
    void operator=(const T&);
    void read_val(T&);
private:
    T val;
};

template<typename T> T& S<T>::get() { return val; }

template<typename T> const T& S<T>::get() const { return val; }

template<typename T> void S<T>::set(const T& v) { val = v; }

template<typename T> void S<T>::operator=(const T& v) { val = v; }

template<typename T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if(!is) return is;
    ss = v;
    return is;
}

template<typename T> void read_val(T& v) { cin >> v; }

template<typename T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for(int i = 0; i < d.size(); ++i){
        os << d[i];
        if(i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}

template<typename T> istream& operator>>(istream& is, vector<T>& d)
{
    char ch1, ch2;
    T temp;
    vector<T> v_temp;
    is >> ch1;
    if(!is) return is;
    if(ch1 != '{'){
        is.clear(ios_base::failbit);
        return is;
    }
    while (cin >> temp >> ch2 && ch2==',')
    {
        v_temp.push_back(temp);
    }
    if(ch2 != '}'){
        is.clear(ios_base::failbit);
        return is;
    }
    v_temp.push_back(temp);

    d = v_temp;
    return is;
} 


int main(){

    S<int> s_int = 4;
    S<char> s_ch = 'a';
    S<double> s_double = 3.14;
    S<string> s_str("Hello");
    vector<int> v_int = {1, 2, 3, 4};
    S<vector<int>> s_v_int = v_int;

    // cout << "s_int = " << s_int.val << endl;
    // cout << "s_ch = " << s_ch.val << endl;
    // cout << "s_double = " << s_double.val << endl;
    // cout << "s_str = " << s_str.val << endl;
    // for(size_t i = 0; i != v_int.size(); ++i)
    //     cout << "s_v_int[" << i << "] = " << s_v_int.val[i] << endl; 

    
    cout << "s_int = " << s_int.get() << endl;  
    cout << "s_ch = " << s_ch.get() << endl;
    cout << "s_double = " << s_double.get() << endl;
    cout << "s_str = " << s_str.get() << endl;
    for(size_t i = 0; i != v_int.size(); ++i)
        cout << "s_v_int[" << i << "] = " << s_v_int.get()[i] << endl;

    s_int.set(10);

    cout << "s_int = " << s_int.get() << endl;

    s_int = 11;

    cout << "s_int = " << s_int.get() << endl;

    cout << "s_int: ";
    read_val(s_int);
    cout << "s_ch: ";
    read_val(s_ch);
    cout << "s_double: ";
    read_val(s_double);
    cout << "s_str: ";
    read_val(s_str);
    cout << "\ns_int = " << s_int.get() << endl
        << "s_ch = " << s_ch.get() << endl
        << "s_double = " << s_double.get() << endl
        << "s_str = " << s_str.get() << endl;

    cout << "\ns_v_int: ";
    read_val(s_v_int);
    cout << "\ns_v_int: " << s_v_int.get() << endl;

    return 0;