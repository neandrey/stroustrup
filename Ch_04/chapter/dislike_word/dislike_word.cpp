#include "std_lib_facilities.h"

int main(){

	vector<string> words;
	string disliked = "Broccoli";

	for (string temp; cin >> temp;)
		words.push_back(temp);

	//количество слов
	cout << "Количество слов: " << words.size() << endl;

	sort(words);
	for (auto it : words){
		if(it == disliked)
			cout << "BLEEP" << ' ';
		else
			cout << it << ' '; 
	}
	cout << endl;

	return 0;
}
