//базовый калькулятор.
#include "std_lib_facilities.h"

int main(){

	string operation;
	double val1, val2;
	cout << "Введите символ операции (+,-,/,*) и два операнда: ";
	cin >> operation >> val1 >> val2;

	if ("plus" == operation or "+" == operation)
		cout << val1 + val2 << endl;
	else if("minus" == operation or "-" == operation)
		cout << val1 - val2 << endl;
	else if("mul" == operation or "*" == operation)
		cout << val1 * val2 << endl;
	else if("div" == operation or "/" == operation){ 
		if (val2 == 0)
			simple_error("На ноль делить нельзя!");
		else
			cout << val1 / val2  << endl;
	}
	else
		cout << "Я не знаю такой операции!" << endl;

		return 0;
}
