#include "std_lib_facilities.h"

struct Reading{
    int hour;
    double temperature;
};

int main(int argc, char const *argv[])
{
    cout << "Введите имя входного файла: ";
    string iname;
    cin >> iname;
    ifstream ist{iname};
    if(!ist) error("Невозможно открыть входной файл ", iname);

    string oname;
    cout << "Введите имя выходного файла: ";
    cin >> oname;
    ofstream ost{oname};
    if(!ost) error("Невозможно открыть выходной файл ", oname);

    vector<Reading> temps;
    int hour;
    double temperature;
    while(ist >> hour >> temperature){
        if(hour < 0 || hour > 23) error("Некорректное время");
        temps.push_back(Reading{hour, temperature});
    }

    for(int i = 0; i < temps.size(); ++i) 
        ost << '(' << temps[i].hour << ','
            << temps[i].temperature << ')' << endl;

    return 0;
}