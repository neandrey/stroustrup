#include "std_lib_facilities.h"

int str_to_digit(string val){

	vector<string> str_numb1 = {"zero", "one", "two", "three", "four",
								"five", "six", "seven", "eight", "nine"};
	
	vector<string> str_numb2 = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

	for (int i = 0; i != str_numb1.size(); ++i) {
		if (str_numb1[i] == val)
			return i; 
		else if (str_numb2[i] == val)
			return i;

	}

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
