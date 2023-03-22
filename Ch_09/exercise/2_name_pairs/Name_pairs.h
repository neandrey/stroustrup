#ifndef NAME_PAIRS_H
#define NAME_PAIRS_H
#include "std_lib_facilities.h"

namespace my_namespace{

class Name_pairs{
public:
    void read_names();
    void read_ages();
    void print();
    void sort();

private:
    vector<string> name;
    vector<double> age;
};
}
#endif