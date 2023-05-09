//стандартные операции для работы с вектором
#include "std_lib_facilities.h" 

int main(){

    vector<double> vd;
    for(double d; cin >> d; )
        vd.push_back(d);

    vector<char> vc(100);
    int n;
    cin >> n;
    vc.resize(n);

    return 0;
}
