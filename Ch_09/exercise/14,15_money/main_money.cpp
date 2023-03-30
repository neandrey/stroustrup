#include "std_lib_facilities.h"
#include "Money.h"

using namespace my_money; 

int main(int argc, char const *argv[])
{
    Money money{123.45};
    cout << money << endl;
    Money money1{200.51};
    cout << money1 << endl;
    Money money2;
    cin >> money2;
    cout << money2 << endl;
    
    return 0;
}
