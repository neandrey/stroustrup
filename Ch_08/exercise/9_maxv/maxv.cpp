#include "std_lib_facilities.h"

double maxv(vector<double> price);
//----------------------------------
int main(int argc, char const *argv[])
{
    vector<double> d_vec = {1, 2, 3, 5, 2, 1, 1, 1, 4};
    double res = 0.0;

    res = maxv(d_vec);

    cout << "max элемент вектора равен: " << res << endl;

    return 0;
}
//------------------------------------------------
double maxv(vector<double> d_vec)
{
    double res = 0.0;

    if(!d_vec.size())
        error("Вектор не имеет элементов");

    sort(d_vec.begin(), d_vec.end());
    return *(d_vec.end()-1);
}
