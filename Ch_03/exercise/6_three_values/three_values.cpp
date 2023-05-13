//ввод 3 целых и вывести в порядке возрастания.
#include "std_lib_facilities.h"

int main(){

	int val1, val2, val3;	
	cout << "Введите три целых числа: ";
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
