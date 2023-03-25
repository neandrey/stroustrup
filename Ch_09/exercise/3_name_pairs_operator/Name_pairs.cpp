#include "Name_pairs.h"

namespace my_namespace{

void Name_pairs::read_names(){

    static const string quit = "|";

    cout << "Введите несколько имен (для выхода |): ";
    for(string temp; cin >> temp; ){
        if(temp == quit)
            return;
        name.push_back(temp);
    }
}

void Name_pairs::read_ages(){

    if(!name.size())
        return;

    double in_age = 0.0;
    cout << "Введите " << name.size() << " возрастa: ";
    for(size_t i = 0; i != name.size(); ++i){
        cin >> in_age;
        if(!cin){
            error("Возраст должен быть double");
        } 
        age.push_back(in_age);
    }
}

void Name_pairs::sort(){

    vector<string> t_name{name};
    vector<double> t_age;

    std::sort(t_name.begin(), t_name.end());

    for(auto t_str : t_name)
        for(size_t i = 0; i != name.size(); ++i)
            if(t_str == name[i])
                t_age.push_back(age[i]);  

    name = t_name;
    age = t_age;
}

ostream &operator<<(ostream &os, const Name_pairs &np){

    for(size_t i = 0; i != np.get_size(); ++i)
        os << np.get_name(i) << " " << np.get_age(i) << endl;
    return os;
}
}