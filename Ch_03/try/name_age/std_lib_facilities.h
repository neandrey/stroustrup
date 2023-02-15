//Ввод имени и возраста
#include "std_lib_facilities.h"

int main(){
	cout << "Пожалуйста, введите свое имя и возраст:\n";
	string first_name = "???";
	double age = -1;
	cin >> first_name >> age;
	cout << "Привет, " << first_name << " (age " << age * 12.0 << ")\n";
	
	return 0;
}
