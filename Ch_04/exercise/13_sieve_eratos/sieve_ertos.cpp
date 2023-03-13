//simple_numb_limit
#include "std_lib_facilities.h"

void simple_numb(int, vector<int>);

int main(){

	vector<int> primes;
	int max;
	
	cout << "Введите верхнюю границу для поиска простых чисел: ";
	cin >> max;
	
	//заполняем массив true
	for (int i = 0; i < max; ++i)
		primes.push_back(true); 
	

	
	for (auto it: primes)
		cout << it << ' ';
	cout << endl;
	
	return 0;
}
//--------------------------
void simple_numb(int n, vector<int> primes){



}
	 
