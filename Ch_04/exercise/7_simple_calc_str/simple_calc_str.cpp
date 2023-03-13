#include "std_lib_facilities.h"
/*В русском переводе есть неточность в переводе именно одиноченое число 
Modify the “mini calculator” from exercise 5 to accept (just) single-digit
numbers written as either digits or spelled out.
*/

int str_to_digit(string val) {
	/*поиск значеня в числах либо в строках, если не нашли -1*/

	vector<string> str_numb = {"zero", "one", "two", "three", "four",
								"five", "six", "seven", "eight", "nine"};
	
	vector<string> numb_numb = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	for (size_t i = 0; i != str_numb.size(); ++i) 
		if (str_numb[i] == val)
			return i; 

	for (size_t i = 0; i != numb_numb.size(); ++i) 
		if (numb_numb[i] == val)
			return i; 
	
	return -1;	
}


int main(){

	string arg1, arg2; 
	int val1, val2, res;
	char operation;
	string s_oper;


	cout << "Введите два аргумента типа double" <<
	 	" и знак операции (+, -, *, /): ";

	cin >> arg1 >> arg2 >> operation;

	val1 = str_to_digit(arg1);
	val2 = str_to_digit(arg2);

	if(!val1 or !val2)
		error("Ошибка, неправильно ввели аргумент!");

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
