#include "std_lib_facilities.h"

int main(){
	
	constexpr double cm_per_inch = 2.54;
	double length = 1;
	char unit = 'a';

	cout << "Пожалуйста, введите длину "
		<< "и единицу измерения (с или i): ";

	cin >> length >> unit;

	switch (unit){
		case 'i':
			cout << length << "in = "
				<< cm_per_inch * length << "cm" << endl;
			break;
		case 'c':	
		cout << length << "cm = "
			<< length / cm_per_inch << "in" << endl;
			break;
		default:
			cout << "Извините, я не знаю, что такое "
				<< unit << endl;
			break;
	}

	return 0;
}
