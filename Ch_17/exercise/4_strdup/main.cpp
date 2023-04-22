//копируем C-строку в динамически выделенную память
#include "std_lib_facilities.h" 

size_t length(const char * s);
char* strdup(const char* s);

int main(){

    char s1[] = "Hello world";
    char* s2; 

    s2 = strdup(s1);

    cout << s2 << endl;

    return 0;
}

char* strdup(const char* s){
// копирование строк    
    if(!s) return ""; 

    char* c_str = new char[length(s)+1];

    for (size_t i = 0; i < length(s); ++i){
        c_str[i] = s[i];
    }
    c_str[length(s)+1] = '\0';

    return c_str;
}

size_t length(const char *s)
//длина строки
{
    size_t len = 0;
    while (*s != '\0'){
        ++len;
        ++s;
    }

    return len;
}
