#include "std_lib_facilities.h"

int main(){
	
	constexpr double cm_per_inch = 2.54;
	double length = 1;
	char unit = 0;

	cout << "Пожалуйста, введите длину "
		<< "и единицу измерения (с или i): ";

	cin >> length >> unit;

	if (unit == 'i')
		cout << length << "in = "
			<< cm_per_inch * length << "cm" << endl;
	else if(unit == 'c')
		cout << length << "cm = "
			<< length / cm_per_inch << "in" << endl;
	else
		cout << "Извините, я не знаю, что такое "
			<< unit << endl;

	return 0;
}
