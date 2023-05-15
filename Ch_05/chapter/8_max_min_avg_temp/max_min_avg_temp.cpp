#include "std_lib_facilities.h"

int main(int argc, char const *argv[])
{
    vector<double> temps;

    double sum = 0;
    double high_temp = -1000;
    double low_temp = 1000;
    int no_of_temps = 0;

    for(double temp; cin >> temp; ){
        ++no_of_temps;
        sum += temp;
        if(temp > high_temp) high_temp = temp;
        if(temp < low_temp) low_temp = temp;
    }

    cout << "Максимальная температура: "
        << high_temp << endl;
    cout << "Минимальная температура: "
        << low_temp << endl;
    cout << "Средняя температура: "
        << sum/no_of_temps << endl;

    return 0;
}
