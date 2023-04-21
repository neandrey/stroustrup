//dynamic_memory
#include "std_lib_facilities.h" 

void to_lower(char* s);
int chr_to_int(char s);
char int_to_chr(int n);

int main(){

    char s[] = "Hello, World!";

    to_lower(s);

    cout << s << endl;

    return 0;
}

void to_lower(char *s)
{

    if(!s)
        return;
        
    while(*s != '\0'){
        if(*s >= 'A' and *s <= 'Z'){
            *s = int_to_chr(chr_to_int(*s) + 32);
        }
        ++s;
    }
    
}

int chr_to_int(char s)
//преобразуем char->int
{
    return int(s);
}

char int_to_chr(int n)
//преобразуем int->char
{
    return char(n);
}