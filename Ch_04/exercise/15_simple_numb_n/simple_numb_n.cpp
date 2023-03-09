//simple_numb_n
#include "std_lib_facilities.h"

bool simple_numb(int);

int main(){

	int  count = 2, numb;
	cout << "Enter n number: ";
	cin >> numb; 

	if(numb < 0)
		error("Введено неправильное число");

	while (numb != 0) {
		if (simple_numb(count)){
			cout << count << ' ';
			--numb;
		}
		++count;
	} 
	cout << endl;

	return 0;
}
//--------------------------
bool simple_numb(int n){
	for (int i = 2; i < n; ++i)
	 if (n % i == 0)
		 return false;
	return true;
}	 
