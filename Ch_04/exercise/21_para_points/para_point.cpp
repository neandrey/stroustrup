//sqr_equation ax2 + b + c = 0
#include "std_lib_facilities.h"

int find_score(int, vector<int>, vector<string>);
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

	cout << "find score: ";
	cin >> score;

	int res = find_score(score, scores, names);
	if(!res)
		cout << "Баллы не найдены." << endl;


	return 0;
}
//-------------------------------------------
int find_score(int score, vector<int> scores, vector<string> names){

	int res = 0;
	for (size_t i = 0; i != scores.size(); ++i){
		if (score == scores[i]){
			cout << names[i] << ' ';
			++res;
		}
	}

	return res;
}