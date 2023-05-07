//findx() - нахождение первого вхождения
#include "std_lib_facilities.h" 

char* findx(const char* s, const char* x);
size_t find_len(const char* s, const char* x);

int main(){

    const char* s = "Hello, world!";
    const char* x = "worlxxxxx ";

    cout << findx(s, x) << endl;

    return 0;
}

char* findx(const char* s, const char* x){
//поиск первого вхождения в строку

    char* find = new char(find_len(s, x));
    char* p_find = find;

    while(*s != '\0'){
        if(*s == *x){
            *find = *s;
            ++x;
            ++find;
        }
        ++s;
    }

    return p_find;
}

size_t find_len(const char* s, const char* x){
//длина строки
    size_t len = 0;
    while(*s != '\0'){
        if(*s == *x){
            ++len;
            ++x;
        }
        ++s; 
    }
    return len;
}
