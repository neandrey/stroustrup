#include "std_lib_facilities.h"

void print(const vector<string> &i_vec, const string label);
vector<string> rev_vector_no_change(const vector<string> v);
vector<string> &rev_vector_change(vector<string> &v);
//----------------------------------
int main(int argc, char const *argv[])
{
    vector<string> v1 = {"one", "two", "three", "four", "five"};
    vector<string> v2;

    
    v2 = rev_vector_no_change(v1);
    print(v1, "v1: ");
    print(v2, "v2: ");
    cout << endl;

    v2 = rev_vector_change(v1);
    print(v1, "v1: ");
    print(v2, "v2: ");


    return 0;
}
//------------------------------------------------
vector<string> rev_vector_no_change(const vector<string> v){

    vector<string> temp = v;
    
    for(size_t i = 0; i != temp.size() / 2; ++i)
        swap(temp[i], temp[temp.size() - 1 - i]);

    return temp;
}
//-----------------------------------------------
vector<string> &rev_vector_change(vector<string> &v){

    for(size_t i = 0; i != v.size() / 2; ++i)
        swap(v[i], v[v.size() - 1 - i]);

    return v;
}
//------------------------------------------------
void print(const vector<string> &i_vec, const string label){
    
    cout << label;
    for(auto i = i_vec.cbegin(); i != i_vec.cend(); ++i){
        if(i == i_vec.cend() - 1)
            cout << *i << '.';
        else
            cout << *i << ", ";
    }
    cout << endl;

}
//--------------------------------------------------