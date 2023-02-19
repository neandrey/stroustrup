#include "std_lib_facilities.h"

int main(){

	double val1, val2, res;
	char operation;
	string s_oper;

	cout << "Введите два аргумента типа double" <<
	 	" и знак операции (+, -, *, /): ";

	cin >> val1 >> val2 >> operation;

	switch(operation){
		case '+':
			s_oper = "Сумма";
			res = val1 + val2;
			break;
		case '-':
			s_oper = "Разность";
			res = val1 - val2;
			break;
		case '*':
			s_oper = "Произведение";
			res = val1 * val2;	
			break;
		case '/':
			if (!val2)
				simple_error("На ноль делить нельзя!");
			s_oper = "Частное";
			res = val1 / val2;
			break;
	}
			
	cout << s_oper+' ' << val1 <<  " и " << val2
		<< " равна " << res << endl; 


	return 0;
}
