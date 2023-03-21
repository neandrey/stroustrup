#include "std_lib_facilities.h"

struct Return_value{
    double min;
    double max;
    double mediana;
};

Return_value &max_min_mediana(vector<double> d_vec, Return_value &r_val);
//------------------------------------------
int main(int argc, char const *argv[])
{
    vector<double> d_vec = {1, 2, 3, 4};
    Return_value r_val;

    r_val = max_min_mediana(d_vec, r_val);

    cout << "max элемент вектора равен: " << r_val.max << '\n' 
        << "min элемент вектора равен: " << r_val.min << '\n'
        << "mediana вектора равна: " << r_val.mediana
        << endl;

    return 0;
}
//------------------------------------------------
Return_value &max_min_mediana(vector<double> d_vec, Return_value &r_val)
{
    size_t len = d_vec.size();
    size_t half_len = len / 2;

    if(!len)
        error("Вектор пуст");

    sort(d_vec.begin(), d_vec.end());
    r_val.max = *(d_vec.end()-1);
    r_val.min = *d_vec.begin();

    if(d_vec.size() % 2 != 0)
        r_val.mediana = d_vec[half_len];
    else{
        r_val.mediana = (d_vec[half_len] + d_vec[half_len - 1]) / 2.0;
    }
    return r_val;
}
//---------------------------------------------------
