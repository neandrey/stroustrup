#include "std_lib_facilities.h"


class Token{
public:
    char kind;
    double value;
};

int main(int argc, char const *argv[])
{
    Token t;
    t.kind = '+';
    Token t2;
    t2.kind = '8';
    t2.value = 3.14;

    Token tt = t;
    if(tt.kind != t.kind) error("невозможно!");
    t = t2;
    cout << t.value << endl;

    {//Token t1 and t2
        Token t1{'+'};
        Token t2{'8', 11.5};

        cout << t1.kind << endl;
        cout << t2.kind << ' ' << t2.value << endl;
    }

    return 0;
}