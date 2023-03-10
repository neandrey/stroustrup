//sqr_equation ax2 + b + c = 0
#include "std_lib_facilities.h"

int find_name(string, vector<string>);
int main(){

	vector<string> names;
	vector<int> scores;
	string name;
	int score;

	while(true){
		
		cout << "name and score (Joe 17): ";
		cin >> name >> score;

		if (name == "NoName" and score == 0)
			break;
		
		for (auto n :names)
			if (n == name)
				error("Имя уже встречалось!");

		names.push_back(name);
		scores.push_back(score);

	}	

	cout << "find name: ";
	cin >> name;

	int res = find_name(name, names);
	if (res < 0)
		cout << "Имя не найденo." << endl;
	else
		cout << scores[res] << endl;


	return 0;
}
//-------------------------------------------
int find_name(string name, vector<string> names){

	for (size_t i = 0; i != names.size(); ++i)
		if (name == names[i])
			return i;

	return -1;
}