//Ввод имени и отчества 
#include "std_lib_facilities.h"

int main(){
	cout << "Пожалуйста, введите два имени: ";
	string first, second;
	cin >> first >> second;

	if(first == second)
		cout << "Имена совпадают\n";
	if(first < second)
		cout << first << " предшествует " << second
			<< " в алфавитном порядке\n";
	if(first > second)
		cout << first << " следует за " << second
			<< " в алфавитном порядке\n";

	return 0;
}
