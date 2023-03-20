#include "std_lib_facilities.h"

int find_age(const vector<string> &v_name, const vector<int> &v_age, const string find_name);
//----------------------------------
int main(int argc, char const *argv[])
{
    vector<string> v_name;
    string name;
    vector<int> v_age;
    int age;

    //вводим 5 имен
    cout << "Введи 5 имен: ";
    for(size_t i = 0; i != 5; ++i){
        cin >> name;
        v_name.push_back(name);
    }

    //вводим возраст
    for(auto n : v_name){
        cout << "Введите возраст для " << n << ": ";
        cin >> age;
        v_age.push_back(age);
    }

    vector<string> copy_name{v_name};

    sort(v_name.begin(), v_name.end());

    for(auto n : v_name){
        cout << n << ' ' << find_age(copy_name, v_age, n) << endl;
    }
   
    return 0;
}
//------------------------------------------------
int find_age(const vector<string> &v_name, const vector<int> &v_age, const string find_name)
{
    for(size_t i = 0; i != v_name.size(); ++i)
        if(v_name[i] == find_name)
            return v_age[i];

    error("Нет такого имени");

}
