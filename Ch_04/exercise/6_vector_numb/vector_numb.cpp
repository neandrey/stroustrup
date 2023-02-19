#include "std_lib_facilities.h"

int main(){
	
	vector<string> s_number = {"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};

	for (int temp; cin >> temp;){
		cout << s_number[temp] << endl;
	}


	return 0;
}
