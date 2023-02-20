#include "std_lib_facilities.h"

int main(){

	
	vector<string> s_number = {"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};
/*
	for (int temp; cin >> temp;){
		cout << s_number[temp] << endl;
	}
	*/
	

	for (string temp; cin >> temp;)
		for(int i = 0; i < s_number.size(); ++i)
			if (s_number[i] == temp)
				cout << i << endl; 
	
	return 0;
}
