#include "std_lib_facilities.h"

double some_function(){

    double d = 0;
    cin >> d;
    if(!cin)
        error("Не могу считать число double"
        " в 'some_function()' ");
    
    return d;
}

int main()
{
    cout << some_function() << endl;

    return 0;
}
