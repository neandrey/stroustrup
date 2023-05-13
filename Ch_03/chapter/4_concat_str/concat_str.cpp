//Ввод имени и отчества 
#include "std_lib_facilities.h"

int main(){
	cout << "Пожалуйста, введите свое имя и отчество: ";
	string first, second;
	cin >> first >> second;

	string name = first + ' ' + second;
	cout << "Привет, " << name << '\n';

		return 0;
}
