//ввод 3 строки и вывести в порядке возрастания.
#include "std_lib_facilities.h"

int main(){

	string val1, val2, val3;	
	cout << "Введите три строки: ";
	cin >> val1 >> val2 >> val3;

	(val1 <= val2) ?
		((val2 <= val3) ? cout << val1 << val2 << val3 :
		(val3 <= val1) ? cout << val3 << val1 << val2 :
		cout << val1 << val3 << val2)
		:
		((val1 <= val3) ? cout << val2 << val1 << val3 :
		(val3 <= val2) ? cout << val3 << val2 << val1 :
		cout << val2 << val3 << val1);

	cout << endl;

	return 0;
}
