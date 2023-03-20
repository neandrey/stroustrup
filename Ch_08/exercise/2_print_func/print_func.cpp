#include "std_lib_facilities.h"

void print(const vector<int> &i_vec, const string label);

int main(int argc, char const *argv[])
{
    vector<int> i_vec = {1, 2, 3, 4, 5, 6, 7};
    string label = "out: ";

    print(i_vec, label);

    return 0;
}
//------------------------------------------------
void print(const vector<int> &i_vec, const string label){
    
    cout << label;
    for(auto i = i_vec.cbegin(); i != i_vec.cend(); ++i){
        if(i == i_vec.cend() - 1)
            cout << *i;
        else
            cout << *i << ", ";
    }
    cout << endl;

}
