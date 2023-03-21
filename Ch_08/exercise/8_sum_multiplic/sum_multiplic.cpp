#include "std_lib_facilities.h"

double sum_multiplication(const vector<double> &price, const vector<double> &weight);
//----------------------------------
int main(int argc, char const *argv[])
{
    vector<double> price = {1, 2, 3, 4};
    vector<double> weight = {1, 2, 3, 4};
    double res = 0.0;

    res = sum_multiplication(price, weight);

    cout << "Сумма произведений векторов равна: " << res << endl;

    return 0;
}
//------------------------------------------------
double sum_multiplication(const vector<double> &price, const vector<double> &weight)
{
    double res = 0.0;
    if(price.size() == weight.size()){
        for(size_t i = 0; i != price.size(); ++i)
            res += price[i] * weight[i];
        return res;
    }else{
        error("Размеры выекторов не равны.");
    }
}
