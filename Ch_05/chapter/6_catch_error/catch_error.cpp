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
    try{
        some_function();
        return 0;
    }
    catch(runtime_error& e){
        cerr << "runtime error: " << e.what() << '\n';
        return 1;
    }

}
