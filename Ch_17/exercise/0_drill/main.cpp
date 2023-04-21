//dynamic_memory
#include "std_lib_facilities.h" 

void init_array(int* a, int n, int first_val);
void print_array10(ostream& os, int* a);
void print_array(ostream& os, int* a, int n);

void init_vector(vector<int>& v, int first_val);
void print_vector(ostream& os, const vector<int>& v);

int main(){

//array
    int first = 100;
    int size_arr = 10;
    int* int_arr = new int[size_arr];

    init_array(int_arr, size_arr, first);
    print_array10(cout, int_arr);
    cout << endl;

    delete[] int_arr;

    size_arr = 11;
    int* int_arr2 = new int[size_arr];

    init_array(int_arr2, size_arr, first);
    print_array(cout, int_arr2, size_arr);
    cout << endl;

    delete[] int_arr2;

    size_arr = 20;
    int* int_arr3 = new int[size_arr];

    init_array(int_arr3, size_arr, first);
    print_array(cout, int_arr3, size_arr);
    cout << endl;

    delete[] int_arr3;

//vector
    vector<int> i_v1(10);
    vector<int> i_v2(11);
    vector<int> i_v3(20);

    init_vector(i_v1, first);
    init_vector(i_v2, first);
    init_vector(i_v3, first);

    print_vector(cout, i_v1); cout << endl;
    print_vector(cout, i_v2); cout << endl;
    print_vector(cout, i_v3); cout << endl;

// part II
    int* p = new int{7};
    cout << "";

    return 0;
}
void init_array(int *a, int n, int first_val)
//инициализация элементов массива
{
    for (int i = 0; i < n; ++i)
        a[i] = first_val + i;
}

void print_array10(ostream &os, int *a)
//выводит 10 элементов массива на печать
{
    for (int i = 0; i < 10; ++i)
        os << a[i] << ' ';

}

void print_array(ostream &os, int *a, int n)
//выводит n элементов массива на печать
{
    for (int i = 0; i < n; ++i)
        os << a[i] << ' ';
}

void init_vector(vector<int> &v, int first_val)
//инициализация вектора
{
    for (int i = 0; i < v.size(); ++i)
        v[i] = first_val + i;
}

void print_vector(ostream &os, const vector<int> &v)
//вывод на печать значений vector 
{
    for (auto i : v)
        os << i << ' ';
}
