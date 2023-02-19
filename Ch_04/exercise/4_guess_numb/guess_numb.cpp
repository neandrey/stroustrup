#include "std_lib_facilities.h"

int main(){

	int number, res, min, max;
	min = 0; 
	max = 100;
	char answer = 'a';

	cout << "Загадайте число от 1 до 100 и введите его: ";
	cin >> number;
	
	for (int i = 0; i < 7; ++i){
		res = (min + max) / 2;
		if (res == number){
			cout << "Вы нашли загаданное число: " << res << endl;
			break;
		}
		cout << "Выбранное число больше " << res << " (y/n): ";
	 	cin >> answer;

		if (answer == 'y')
			min = res;
				
		else if (answer == 'n')
		 	max = res;	

		else
			cout << "Не знаяю, что за значение " << answer << endl;
	}

	return 0;
}
