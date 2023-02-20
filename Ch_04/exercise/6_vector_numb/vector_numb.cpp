#include "std_lib_facilities.h"

int main(){

	
	vector<string> s_number = {"zero", "one", "two", "three", "four",
		"five", "six", "seven", "eight", "nine"};
/*
	for (int temp; cin >> temp;){
		cout << s_number[temp] << endl;
	}
	*/
	

	for (string temp; cin >> temp;){
		int i = 0;
		for(auto it : s_number){
			if (it == temp)
				cout << i << endl; 
			++i;
		}
	}
	
	return 0;
}
