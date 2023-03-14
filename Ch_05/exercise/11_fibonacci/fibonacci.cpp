//fibonnaci
#include "std_lib_facilities.h"

//--------------------------------------------
//Найти наибольшее число которое можно записать в переменную int
//--------------------------------------------
int main(){
	
	int first = 1, second = 1;
	cout << first << ' ' << second << ' ';

	while(true){

		int temp = second;
		second += first;
		if (second < 0)
			break;
		cout << second << ' ';
		first = temp;
	}
	
	return 0;
}
