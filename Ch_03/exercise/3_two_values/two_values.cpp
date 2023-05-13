//преобразование миль в км.
#include "std_lib_facilities.h"

int main(){

	int val1, val2;	
	cout << "Введите два целых числа: ";
	cin >> val1 >> val2;

	if (val1 > val2)
		cout << "Значение " <<  val1 << " > " << val2 << endl;
	else
		cout << "Значение " <<  val1 << " < " << val2 << endl;

	cout << "Сумма " << val1 << " + " <<  val2 <<
		" = " << val1 + val2 << endl;
	cout << "Разность " << val1 << " - " << val2
	 <<	" = " << val1 - val2 << endl;
	cout << "Произведение " << val1 << " * " <<  val2 <<
	 " = " << val1 * val2 << endl;
	cout << "Частное " <<  val1 << " / " <<  val2 <<
	 " = " << val1 / val2 << endl;
	
	return 0;
}
