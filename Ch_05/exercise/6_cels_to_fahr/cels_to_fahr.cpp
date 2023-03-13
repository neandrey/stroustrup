//cels_to_fahr
#include "std_lib_facilities.h"

//------------------------------
double ctof(double c){

    return (c * 9.0/5) + 32.0; 
}
//-----------------------------
double ftoc(double f){

    return  5.0/9 *(f  - 32.0);
}

int main(){
    
    double cel = 0;
    cout << "Введите C: ";
    cin >> cel;
    double fahr = ctof(cel); 
    cout << "градусы F: "<< fahr << endl;

    fahr = 0;
    cout << "Введите F: ";
    cin >> fahr;
    cel = ftoc(fahr);
    cout << "градусы C: " <<  cel << endl;

    return 0;
}