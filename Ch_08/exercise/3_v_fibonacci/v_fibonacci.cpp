#include "std_lib_facilities.h"

void print(const vector<int> &i_vec, const string label);
vector<int> fibonacci(int v1, int v2, vector<int> v_fib, size_t n);
void valid_input(int a);

int main(int argc, char const *argv[])
{
    vector<int> v_feb;
    int x, y;
    size_t n;
    string label = "out: ";

    cout << "Введите 1-ое и 2-ое число последовательности: ";
    cin >> x >> y;
    if(!cin){
        error("Неправильный ввод переменных int");
    }
    valid_input(x);
    valid_input(y);

    cout << "Введите n - кол-во чисел в последовательности: ";
    cin >> n;
    if(!cin){
        error("Неправильный ввод переменной n");
    }
    valid_input(n);

    v_feb = fibonacci(x, y, v_feb, n);
    print(v_feb, label);

    return 0;
}
//------------------------------------------------
void print(const vector<int> &i_vec, const string label){
    
    cout << label;
    for(auto i = i_vec.cbegin(); i != i_vec.cend(); ++i){
        if(i == i_vec.cend() - 1)
            cout << *i << '.';
        else
            cout << *i << ", ";
    }
    cout << endl;

}
//--------------------------------------------------
vector<int> fibonacci(int v1, int v2, vector<int> v_fib, size_t n){

    int temp = 0;
    for(size_t i = 0; i != n; ++i){
        if(i == 0)
            v_fib.push_back(v1);
        else if(i == 1)
            v_fib.push_back(v2);
        else{
            temp = v2;
            v2 += v1;
            v_fib.push_back(v2);
            v1 = temp;
        }
    }

    return v_fib;
}
//-------------------------------------------------
void valid_input(int a){

    if(a < 0) error("Числа должны быть положительными");
}