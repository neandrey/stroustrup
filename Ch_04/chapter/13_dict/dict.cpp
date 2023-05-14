#include "std_lib_facilities.h"

int main(){

	vector<string> words;

	for (string temp; cin >> temp;)
		words.push_back(temp);

	//количество слов
	cout << "Количество слов: " << words.size() << endl;

	sort(words);
	for (int i = 0; i < words.size(); ++i)
		if(i == 0 or words[i-1] != words[i])
			cout << words[i] << endl;

	return 0;
}
