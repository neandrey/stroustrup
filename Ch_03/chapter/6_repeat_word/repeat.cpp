//Подсчет повторов слов
#include "std_lib_facilities.h"

int main(){

	string previos = "";
	string current;

	while (cin >> current){
		if (previos == current)
			cout << "Повторяющееся слово: " << current << '\n';
		previos = current;
	}
	
		return 0;
}
