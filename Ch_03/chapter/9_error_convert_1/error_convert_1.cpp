//Сужающие преобразования версия 1
#include "std_lib_facilities.h"

int main(){

	int a = 20000;
	char c = a;

	int b = c;
	if(a != b)
		cout << "Ой!: " << a << "!=" << b << '\n';
	else
		cout << "Ого! Однако у нас очень большой char\n";

	return 0;
}
