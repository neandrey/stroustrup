#include "std_lib_facilities.h"

vector<int> count_symbol(const vector<string> &v_str);
int max_len_str(const vector<string> &v_str);
int min_len_str(const vector<string> &v_str);
string max_str(vector<string> v_str);
string min_str(vector<string> v_str);
//------------------------------------------
int main(int argc, char const *argv[])
{
    vector<string> s_vec = {"one", "two", "three", "five", "six"};
    vector<int> i_vec;
    int max_len_s, min_len_s;
    string max_s, min_s;

    i_vec = count_symbol(s_vec);

    for(auto n : i_vec)
        cout << n << ' ';
    cout << endl;

    max_len_s = max_len_str(s_vec);
    cout << max_len_s << endl;

    min_len_s = min_len_str(s_vec);
    cout << min_len_s << endl;

    return 0;
}
//------------------------------------------------
vector<int> count_symbol(const vector<string> &v_str){

    vector<int> res;
    for(size_t i = 0; i != v_str.size(); ++i)
        res.push_back(v_str[i].size());

    return res;
}
//---------------------------------------------------
int max_len_str(const vector<string> &v_str){

    string max;

    for(auto str : v_str)
        if(str.size() > max.size())
            max = str;
    
    return max.size();
}
//-----------------------------------------------------
int min_len_str(const vector<string> &v_str)
{
    if(!v_str.size())
        return 0;

    string min = v_str.front();

    for (auto str : v_str)
        if(str.size() < min.size())
            min = str;
    
    return min.size();
}
//-----------------------------------------------------
