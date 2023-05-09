//not push_back()
#include "std_lib_facilities.h" 

int main(){

    vector<double>* p = new vector<double>(10);
    int n = 10;
    for(double d; cin >> d; ){
        if(n == p->size()){
            vector<double>* q = new vector<double>(p->size()*2);
            copy(p->begin(), p->end(), q->begin());
            delete p;
            p = q;
        }
        (*p)[n] = d;
        ++n;
    }

    return 0;
}
