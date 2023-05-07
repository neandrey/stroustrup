//strdup()
#include "std_lib_facilities.h" 

char* strdup(const char* s);
size_t strlen(const char* s);
void copy_str(const char* s, char* copy_s);

int main(){

    cout << strdup("Hello, world!") << endl;

    return 0;
}

char* strdup(const char* s){

    char* copy_s = new char[strlen(s)+1];

    char* p_str = copy_s;
    copy_str(s, copy_s);

    return p_str;
}

size_t strlen(const char* s){
//длина строки

    size_t len = 0;
    while(*s != '\0'){
        len++;
        ++s;
    }

    return len;
}

void copy_str(const char *s, char *copy_s){
//копирование строки

    while(*s != '\0'){
        *copy_s = *s;
        ++copy_s;
        ++s;
    }
    *copy_s = '\0';
}
