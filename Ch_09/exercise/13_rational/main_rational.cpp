#include "std_lib_facilities.h"
#include "Rational.h"

int main(int argc, char const *argv[])
{
    Rational r1{3, 9};
    Rational r2{3, 2};
    Rational r3;
    
    r3 = r1 * r2;
    cout << r3 << endl;
    cout << convert(r1) << endl;
    return 0;
}
