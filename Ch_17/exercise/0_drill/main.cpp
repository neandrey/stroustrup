//dynamic_memory
#include "std_lib_facilities.h" 

void init_array(int* a, int n, int first_val);
void init_arr_pow_of_two(int* a, int n);
void print_array10(ostream& os, int* a);
void print_array(ostream& os, int* a, int n);

void init_vector(vector<int>& v, int first_val);
void init_vector_pow_of_two(vector<int>& v);
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

//array
    int* p1 = new int{7};
    cout << "p1 = " << p1 << "; cодержимое p = " << *p1 << endl;

    size_arr = 7;
    int* p2 = new int[size_arr];

    init_arr_pow_of_two(p2, size_arr);

    cout << "p2 = " << p2 << " value = ";
    print_array(cout, p2, size_arr); 
    cout << endl;

    int* p3 = p2;
    p2 = p1;
    p2 = p3;

    cout << "p1 = " << p1 << "; cодержимое p1 = " << *p1 << endl;
    cout << "p2 = " << p2 << "; cодержимое p2 = " << *p2 << endl;

    delete p1;
    delete[] p2, p3;

    size_arr = 10;
    p1 = new int[size_arr];

    init_arr_pow_of_two(p1, size_arr);

    p2 = new int[size_arr];

    p2 = p1;

    print_array(cout, p2, size_arr);
    cout << endl;

//vector
    vector<int> v1(10);
    vector<int> copy_v1(10);
    
    init_vector_pow_of_two(v1);
    copy_v1 = v1;

    cout << "vector copy_v1 = ";
    print_vector(cout, copy_v1);
    cout << endl;


    return 0;
}
void init_array(int *a, int n, int first_val)
//инициализация элементов массива
{
    for (int i = 0; i < n; ++i)
        a[i] = first_val + i;
}

void init_arr_pow_of_two(int *a, int n)
//инициализация массива степенью двойки
{
    for (int i = 0; i < n; ++i){
        if(i == 0)
            a[i] = 1;
        else if(i == 1)
            a[i] = 2;
        else
            a[i] = int(pow(2, i));
    }

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

void init_vector_pow_of_two(vector<int> &v)
//инициализация вектора степенью двойки
{
    for (int i = 0; i < v.size(); ++i){
        if(i == 0)
            v[i] = 1;
        else if(i == 1)
            v[i] = 2;
        else
            v[i] = int(pow(2, i));
    }
}

void print_vector(ostream &os, const vector<int> &v)
//вывод на печать значений vector 
{
    for (auto i : v)
        os << i << ' ';
}
