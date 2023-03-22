#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H
#include "std_lib_facilities.h"

namespace my_namespace{

class Name_pairs{
public:
    void read_names();
    void read_ages();
    void sort();
    string get_name(size_t i) const { return name[i]; }
    double get_age(size_t i) const { return age[i]; }
    size_t get_size() const { return name.size(); }

private:
    vector<string> name;
    vector<double> age;
};
ostream &operator<<(ostream &os, const Name_pairs &np);

}
#endif