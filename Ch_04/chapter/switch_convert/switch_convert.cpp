#include "std_lib_facilities.h"

int main(){
	
	constexpr double rub_to_dollar = 75.16;
	constexpr double rub_to_euro = 79.66;
	constexpr double rub_to_pound = 89.45;
	double sum = 1;
	char unit = 'a';

	cout << "Пожалуйста, введите сумму в рублях "
		<< "и валюту в которую перевести (d, e, или p): ";

	cin >> sum >> unit;

	switch (unit){
		case 'd':
			cout << sum << " rub = "
				<< rub_to_dollar * sum << " dollar" << endl;
			break;
		case 'e':	
			cout << sum << " rub = "
				<< sum *  rub_to_euro << " euro" << endl;
			break;
		case 'p':
			cout << sum << " rub = "
				<< sum *  rub_to_pound << " gbp" << endl;
			break;
		default:
			cout << "Извините, я не знаю, что такое "
				<< unit << endl;
			break;
	}

	return 0;
}
