//rock, paper, scissors
#include "std_lib_facilities.h"

int main(){

	vector<char> v_answer = {'r', 'p', 's'};
	char c_val = 'a';
	string ptr = "Введите камень, ножницы или бумага (r, p, s): ";	
	int i = 3;
	
	while(v_answer.size()){
		char answer = v_answer.back();
		v_answer.pop_back();

		cout << ptr;
		switch (c_val){
			case 'r':
				;
				break;
			case 'p':
				;
				break;
			case 's':
				;
				break;
			default:
				cout << "Не знаю такого значения " << c_val << endl;
				break;
		}
	}

	return 0;
}
