//перевод рублей в доллары и наоборот
#include "std_lib_facilities.h"

int main(){
	
	constexpr double rub_per_dollar = 75.16;
	double sum = 1;
	char unit = 0;

	cout << "Пожалуйста, введите сумму "
		<< "и единицу валюты (r или d): ";

	cin >> sum >> unit;

	if (unit == 'd')
		cout << sum << " dollar = "
			<< rub_per_dollar * sum << " rub" << endl;
	else if(unit == 'r')
		cout << sum << " rub = "
			<< sum / rub_per_dollar << " dollar" << endl;
	else
		cout << "Извините, я не знаю, что такое "
			<< unit << endl;

	return 0;
}
