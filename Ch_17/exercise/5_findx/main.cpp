//находим первое вхождение в C-строке. 
#include "std_lib_facilities.h" 

char* findx(const char* s, const char* x);
pair<int, int> first_and_len(const char* s, const char* x);

int main(){

    char* s = "Hello, World!";
    char* find_s = "Work"; 
    char* res; 

    res = findx(s, find_s);

    cout << res << endl;
    delete[] res;

    return 0;
}

char* findx(const char* s, const char* x){
// нахождение первого вхождения   

    if(!s) return "";
    pair<int, int> fe_pair;

    fe_pair = first_and_len(s, x);
    
    //cout << fe_pair.first << ' ' << fe_pair.second << endl;
    size_t len = fe_pair.second;
    size_t first = fe_pair.first;

    if(!len)
        return "";

    char* c_find = new char[len];

    for (size_t i = 0; i < len; ++i){
        c_find[i] = s[first++];
    }
    c_find[len] = '\0';
    
    return c_find;
}

pair<int, int> first_and_len(const char *s, const char* x)
//первое совпадение и длина строки 
{
    size_t first{0}, len{0}; 
    bool f_first{true};

    for (size_t i = 0; s[i]; ++i){
        //cout << s[i] << ' ' << x[len] << endl;
        if(s[i] == x[len]){
            if(f_first){
                first = i;
                f_first = false;
            }
            ++len;
        }
    }
    return pair<int, int>(first, len);
}
