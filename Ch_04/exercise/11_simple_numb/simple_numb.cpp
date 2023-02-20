//rock, paper, scissors
#include "std_lib_facilities.h"

bool simple_numb(int);

int main(){

	vector<int> primes;

	for (int i = 1; i < 101; ++i)
		if (simple_numb(i))
			primes.push_back(i);

	for (auto it: primes)
		cout << it << ' ';
	cout << endl;
	
	return 0;
}
//--------------------------
bool simple_numb(int n){
	if (n == 1)
		return false;
	for (int i = 2; i < n; ++i)
	 if (n % i == 0)
		 return false;
	return true;
}	 
