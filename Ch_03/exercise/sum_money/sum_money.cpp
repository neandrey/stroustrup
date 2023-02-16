//преобразование миль в км.
#include "std_lib_facilities.h"

int main(){

	int one_cent;	
	cout << "Введите количество 1 центовых монет: ";
	cin >> one_cent;

	int five_cent;	
	cout << "Введите количество 5 центовых монет: ";
	cin >> five_cent;

	int ten_cent;	
	cout << "Введите количество 10 центовых монет: ";
	cin >> ten_cent;

	int twenty_five_cent;	
	cout << "Введите количество 25 центовых монет: ";
	cin >> twenty_five_cent;

	int fifty_cent;	
	cout << "Введите количество 50 центовых монет: ";
	cin >> fifty_cent;

	int dollars, cents, sum;
	dollars = cents =  sum = 0;

	sum = one_cent + five_cent * 5 + ten_cent * 10 +
		twenty_five_cent * 25 + fifty_cent * 50;

	//cout << sum << endl;

	dollars = sum / 100;
	cents = sum - dollars * 100;

	cout << "Общая стоимость ваших монет равна " << 
		dollars << " долларов " << cents << " цента." << endl;



		return 0;
}
