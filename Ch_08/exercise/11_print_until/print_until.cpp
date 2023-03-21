#include "std_lib_facilities.h"

void print_units_s(const vector<string> &v, string quit);
void print_units_ss(const vector<string> &v, string quit);

int main(int argc, char const *argv[])
{
    vector<string> s_vec = {"one", "two", "three", "four", "|", "five", "six"};
    string quit = "|";

    print_units_s(s_vec, quit);
    cout << endl;
    print_units_ss(s_vec, quit);
    cout << endl;

    return 0;
}
//----------------------------------------------------
void print_units_s(const vector<string> &v, string quit)
{
    for(auto s : v){
        if(s == quit) return;
        cout << s << ' ';
    }
}

void print_units_ss(const vector<string> &v, string quit)
{
    size_t count = 0;
    for(auto s : v){
        if(s == quit){
            ++count;
            if(count > 1)
                return;
        }
        cout << s << ' ';
    }
}
