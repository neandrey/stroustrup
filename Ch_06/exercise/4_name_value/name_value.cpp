//name_value
#include "std_lib_facilities.h"

class Name_value {
public:
	string name;
	int score;
	Name_value(string n, int s) : name(n), score(s) {}
};

int main(){

	vector<Name_value> n_values;
	string name;
	int score;

	while(true){

		cout << "name and score (Joe 17): ";
		cin >> name >> score;

		if (name == "NoName" and score == 0)
			break;
		
		for (auto n : n_values)
			if (n.name == name)
				error("Name already met!");

		n_values.push_back(Name_value(name, score));

	}	

	for (auto n : n_values)
		cout << n.name << ' ' << n.score << endl;

	return 0;
}
//-------------------------------------------
