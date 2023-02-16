//преобразование миль в км.
#include "std_lib_facilities.h"

int main(){

	string s;
	cout << "Введите строковое значение числа от (0 до 4): ";
	cin >> s;

	if ("ноль" == s)
		cout << 0 << endl;
	else if("один" == s)
		cout << 1 << endl;
	else if("два" == s)
		cout << 2 << endl;
	else if("три" == s)
		cout << 3 << endl;
	else if("четыре" == s)
		cout << 4 << endl;
	else
		cout << "Я не знаю такого числа!" << endl;

		return 0;
}
