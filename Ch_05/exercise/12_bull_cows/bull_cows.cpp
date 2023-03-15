//bull_and_cows
#include "std_lib_facilities.h"


//--------------------------------------------
int main(){

	const int numb_of_digits = 4;
	int n = 0;
	vector<int> in_vec;
	vector<int> res_vec{1, 2, 3, 4};

	//разбор числа (единицы, десятки, сотни,) от пользователя
	cout << "Введите 4-х значное число (например: 1234): ";
	cin >> n;
	for (size_t i = 0; i != numb_of_digits; ++i){
		int pow_numb = static_cast<int>(pow(10, i));
		int mod_numb = n % (pow_numb * 10);
		in_vec.push_back(mod_numb / pow_numb);
	}
	reverse(in_vec.begin(), in_vec.end());

	//подсчет совпадений
	int bull = 0;
	int cows = 0;

	for(size_t i = 0; i != numb_of_digits; ++i)
		for(size_t j = 0; j != numb_of_digits; ++j)
			if(in_vec[i] == res_vec[j]){
				if(i == j)
					++bull;
				else
					++cows;
			}

	//вывод результата
	cout << "Количество быков " << bull << " Количество коров " << cows << endl;

	cout << "Загаданное число: ";
	for(auto i : res_vec)
		cout << i;
	cout << endl;	

	return 0;
}
