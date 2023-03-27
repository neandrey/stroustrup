#include "std_lib_facilities.h"
#include "Rational.h"

using namespace my_rational;

int main(int argc, char const *argv[])
{
    Rational r1{3, 9};
    Rational r2{3, 2};
    Rational r3;
    Rational r4{3, 2};
    
    cout << convert(r1) << endl;
    cout << find_noz(r1, r2) << endl;

    r3 = r1 + r2;
    cout << r3 << endl;

    r3 = r2 - r1;
    cout << r3 << endl;

    r3 = r1 - r2;
    cout << r3 << endl;

    r3 = r1 * r2;
    cout << r3 << endl;

    r3 = r1 / r2;
    cout << r3 << endl;

    if(r2 == r4)
        cout << "r2 equal r4" << endl;

    return 0;
}
