#include "std_lib_facilities.h"

void fill_vector(istream &is, vector<int> &v, char terminator);

int main(){

    vector<int> v_int;
    fill_vector(cin, v_int, 'q');

    for(auto c : v_int){
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}
//------------------------------------------------------------------
void fill_vector(istream &ist, vector<int> &v, char terminator)
{
    for(int i; ist >> i; )
        v.push_back(i);
    
    if(ist.eof()) return;
    
    if(ist.bad()) error("ist поврежден");
    if(ist.fail()){
        ist.clear();
        
        char c;
        ist >> c;
        
        if(c != terminator){
            ist.unget();
            ist.clear(ios_base::failbit);
        }
    }
}
//----------------------------------------------------------------------
