//выбор min или max с помощью if
#include "std_lib_facilities.h"

int main(){

	int a = 0;
	int b = 0;

	cout << "Пожалуйста введите два целых числа: ";
	cin >> a >> b;

	if(a<b)
		cout << "max(" << a << "," << b
			<< ") равно	" << b << '\n';
	else
		cout << "max(" << a << "," << b
			<< ") равно " << a << '\n'; 
	
	return 0;
}
