//palyndrom. 
#include "std_lib_facilities.h" 

//1 global array
const int len = 10;
int ga[len] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void print_array(int arr[], int size){

    for(size_t i = 0; i != size; ++i)
        cout << arr[i] << ' ';
}

void f(int arr[], int size){
    int la[10];

    for(size_t i = 0; i != size; ++i)
        la[i] = ga[i];

    print_array(la, size);
    cout << endl;

    int* p = new int[size];

    for(size_t i = 0; i != size; ++i){
        *p = arr[i];
        p++;
    }

}

int main(){
    f(ga, len);

    return 0;
}
