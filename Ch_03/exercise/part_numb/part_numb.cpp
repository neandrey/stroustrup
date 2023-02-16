//проверка числа на четность.
#include "std_lib_facilities.h"

int main(){

	int val;
	
	cout << "Введите целое числo: ";
	cin >> val;
		
	if(val % 2 == 0)
		cout << "Число " << val << " является четным. ";
	else
		cout << "Число " << val << " является не четным. ";

	cout << endl;

	return 0;
}
