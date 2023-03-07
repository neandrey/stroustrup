#include "std_lib_facilities.h"

int guess_numb(int&, int&);
//-------------------------------------
int main(){

	int number, res, min, max;
	min = 0; 
	max = 100;
	char answer = 'a';

	cout << "Загадайте число от 1 до 100 и введите его: ";
	cin >> number;

	while(true){

		int res = guess_numb(min, max);

		if (res == number){
			cout << "Вы нашли загаданное число: " << res << endl;
			break;
		}

		cout << "Выбранное число больше " << res << " (y/n): ";
	 	cin >> answer;

		switch(answer){
			case 'y':
				min = guess_numb(min, max);
				break;
			case 'n':
				max = guess_numb(min, max);
				break;
			default:
				cout << "Не знаю такого значения: " << answer << endl;
				break;
		}
	}
	
	return 0;
}
//---------------------------------------
int guess_numb(int& min, int& max){
	return (min + max) / 2;
}
