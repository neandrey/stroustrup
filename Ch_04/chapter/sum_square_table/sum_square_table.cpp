#include "std_lib_facilities.h"

int square(int i){
	int sum = 0;
	for (int j = 0; j < i; ++j)
		sum += i;

	return sum;
}

int main(){
	for (int i = 0; i < 100; ++i)
		cout << i << '\t' << square(i) << endl;

	return 0;
}
