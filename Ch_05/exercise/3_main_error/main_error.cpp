//cels_to_kelvin
#include "std_lib_facilities.h"

double ctok(double c){

    double k = c + 273.15; //int
    return k; //int
}

int main(){
    
    double c = 0;
    cin >> c; //d
    if(c < -273.15)
        error("Температура не может быть нижа 0K");
    double k = ctok(c); //"c"
    cout << k << endl;

    return 0;
}