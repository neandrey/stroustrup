//находим первое вхождение в C-строке. 
#include "std_lib_facilities.h" 

char* findx(const char* s, const char* x);


int main(){

    char* s = "Hello, World!";
    char* find_s = "Wor"; 
    char* res; 

    res = findx(s, find_s);

    cout << res << endl;

    return 0;
}

char* findx(const char* s, const char* x){
// нахождение первого вхождения   

    if(!s) return "";
    size_t v1{0}, v2{0}, len{0}, h{0};
    bool f_first{true};

    for (size_t i = 0; s[i]; ++i){
        //cout << s[i] << ' ' << x[h] << endl;
        if(s[i] == x[h]){
            if(f_first){
                v1 = i;
                f_first = false;
            }
            ++h;
        }
    }
    len = h;
    v2 = v1 + len;
    cout << v1 << ' ' << v2 << ' ' << len << endl;

    char* c_find = new char[len+1];

    size_t iiter{0};
    for (v1; v1 < v2; ++v1){
        c_find[iiter++] = s[v1];
    }
    c_find[len+1] = '\0';
    
    return c_find;
}
