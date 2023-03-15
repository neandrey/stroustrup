//bull_and_cows
#include "std_lib_facilities.h"
/*
	init;
	random_guess();
	while(true_game){
	input_user();
	find_number();
	}
*/

const int numb_of_digits = 4;
//------------------------------
int input_user();
vector<int> parsing_number(vector<int>, int);
pair<int, int> find_number(vector<int> in_vec, vector<int> guess_vec);
void print_result(pair<int, int>);
bool game_true(pair<int, int>);
vector<int> random_guess(vector<int> guess_vec);
//-----------------------------------------
int main(){

	int n, numb = 0;
	vector<int> in_vec;
	vector<int> guess_vec(4, 0); //{0, 0, 0, 0}
	pair<int, int> bull_cows{0, 0}; //1-bull, 2-cows

	char answer = 'y';
	do{	
		guess_vec = random_guess(guess_vec);

		while(!game_true(bull_cows)){
			numb = input_user();
			in_vec = parsing_number(in_vec, numb);
			bull_cows = find_number(in_vec, guess_vec);
			print_result(bull_cows);
		}
		
	cout << "Хочешь еще раз сыграть (y/n): ";
	cin >> answer;
	}while(answer != 'n');
	
	return 0;
}
//-----------------------------------------------
int input_user(){
	//ввод 4-х значного числа
	int n;
	cout << "Введите 4-х значное число (например: 1234): ";
	cin >> n;
	if(!cin)
		error("Введено не целое число");

	return n;
}
//-----------------------------------------------
vector<int> parsing_number(vector<int> in_vec, int n){
	//разбор числа (единицы, десятки, сотни,) от пользователя
	for (size_t i = 0; i != numb_of_digits; ++i){
		int pow_numb = static_cast<int>(pow(10, i));
		int mod_numb = n % (pow_numb * 10);
		in_vec.push_back(mod_numb / pow_numb);
	}
	reverse(in_vec.begin(), in_vec.end());

	return in_vec;
}
//------------------------------------------------
pair<int, int> find_number(vector<int> in_vec, vector<int> guess_vec){
	//подсчет совпадений
	int bull = 0;
	int cows = 0;

	for(size_t i = 0; i != numb_of_digits; ++i)
		for(size_t j = 0; j != numb_of_digits; ++j)
			if(in_vec[i] == guess_vec[j]){
				if(i == j)
					++bull;
				else
					++cows;
			}
	
	return pair<int, int>(bull, cows);
}
//-------------------------------------------------
void print_result(pair<int, int> bull_cows){
	//вывод результата
	cout << "Количество быков " << bull_cows.first << '\n'
		<< "Количество коров " << bull_cows.second << endl;
}
//--------------------------------------------------
bool game_true(pair<int, int> bull_cows){
	//продолжать игру или нет
	if(bull_cows.first == numb_of_digits)
		return true;

	return false;
}
//-----------------------------------------------------
vector<int> random_guess(vector<int> guess_vec){
	//заполняем вектор случайными значениями

	srand((unsigned)time(0));
	for (size_t i = 0; i != numb_of_digits; ++i)
		guess_vec[i] = randint(10);

	return guess_vec;
}
//-----------------------------------------------------