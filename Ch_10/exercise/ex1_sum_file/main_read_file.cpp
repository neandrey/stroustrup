#include "std_lib_facilities.h"

//istream &operator>>(istream &is, int v1);
int main(int argc, char const *argv[])
{
    string name = "number_file";
    ifstream ifs{name};
    if(!ifs) error("Невозможно открыть входной файла: ", name);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    int sum = 0;
    for(int temp; ifs >> temp; )
        sum += temp;

    cout << sum << endl;

    return 0;
}

