//Подсчет повторов слов и вывод количества слов.
#include "std_lib_facilities.h"

int main(){

	int number_or_words = 0;
	string previos = "";
	string current;

	while (cin >> current){
		++number_or_words;
		if (previos == current)
			cout << "Повторение словa: " << current 
				<< " после " << number_or_words
				<< " слов." << 	'\n';
		previos = current;
	}
	
		return 0;
}
