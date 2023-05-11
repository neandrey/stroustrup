//0_drill 
#include "std_lib_facilities.h" 

// array 
const int length = 10;
int ga[length] = {1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};

void print_arr(const int arr[], int l);
void f(int arr[], int len)
{
    int la[length];

    //copy ga -> la
    for(size_t i = 0; i != length; ++i)
        la[i] = ga[i];
    
    //print la
    cout << "print la: ";
    print_arr(la, length);

    //указатель p
    int* p = new int[len];

    for(size_t i = 0; i !=len; ++i)
        p[i] = arr[i];

    //print p
    cout << "print p: ";
    print_arr(p, len);

    delete[] p;
}

void print_arr(const int arr[], int l){
//печать массива
    for(size_t i = 0; i != l; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void init_fact(int arr[], int l){
//заполняем факториал
    int sum = 1;
    for(size_t i = 1 ; i <= l; ++i){
        arr[i-1] = sum *= i;
    }
}

// vector
void print_vec(const vector<int>& v);
void init_vector(vector<int>& v);
vector<int> gv{1, 2, 4, 8, 16, 32, 64, 128, 512, 1024};

void f(vector<int> v)
{

    vector<int> lv;
    for(size_t i = 0; i != gv.size(); ++i)
        lv.push_back(gv[i]);

    cout << "print lv: ";
    print_vec(lv);

    vector<int> lv2 = v;

    cout << "print lv2: ";
    print_vec(lv2);
}

void print_vec(const vector<int>& v){
//печать вектора 
    for(size_t i = 0; i != v.size(); ++i)
        cout << v[i] << ' ';
    cout << endl;
}

void init_fact(vector<int>& v){
//инициализация вектора
    int sum = 1;
    for(size_t i = 1; i <= v.size(); ++i)
        v[i-1] = sum *= i;
}

int main()
{
    //array
    f(ga, length);
    int aa[length];
    init_fact(aa, length);
    f(aa, length);

    //vector
    f(gv);
    vector<int> vv(10, 0);
    init_fact(vv);
    f(vv);

    return 0;
}
