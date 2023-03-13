//cels_to_kelvin
#include "std_lib_facilities.h"

double ktoc(double k){

    double c = k - 273.15; 
    return c; 
}

int main(){
    
    double k = 0;
    cin >> k;
    double c = ktoc(k); 
    cout << c << endl;

    return 0;
}