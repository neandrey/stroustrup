//sqr_equation ax2 + b + c = 0
#include "std_lib_facilities.h"

int main(){

	vector<string> names;
	vector<int> scores;
	string name;
	int score;

	while(true){

		cin >> name >> score;

		if (name == "NoName" and score == 0)
			break;
		
		for (auto n :names)
			if (n == name)
				error("Имя уже встречалось!");

		names.push_back(name);
		scores.push_back(score);

	}	

	for (size_t i = 0; i != names.size(); ++i)
		cout << names[i] << ' ' << scores[i] << endl;


	return 0;
}
//--------------------------
