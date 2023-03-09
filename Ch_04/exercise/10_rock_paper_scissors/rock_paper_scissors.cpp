//rock, paper, scissors
#include "std_lib_facilities.h"


int main(){

	vector<char> v_answer = {'r', 'p', 's', 's', 'r', 'p'};
	char c_user = 'a';

	string s_lose = "You lose";
	string s_win = "You win";
	string s_equal = "Once more";

	for (auto c_comp : v_answer) {

		cout << "Введите камень(s), ножницы(r) или бумага(p): ";	
		cin >> c_user;

		switch (c_user){
			case 'r':
				if (c_comp == 's')
					cout << s_lose;
				else if (c_comp == 'p')
					cout << s_win;
				else
					cout << s_equal;
				break;
			case 'p':
				if (c_comp == 'r')
					cout << s_lose;
				else if (c_comp == 's')
					cout << s_win;
				else
					cout << s_equal;
				break;
			case 's':
				if (c_comp == 'p')
					cout << s_lose;
				else if (c_comp == 'r')
					cout << s_win;
				else
					cout << s_equal;
				break;
			default:
				cout << "Не знаю такого значения " << c_user;
				break;
		}
		cout << endl;
	}

	return 0;
}
