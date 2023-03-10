//find_sentence
#include "std_lib_facilities.h"

int main(){

	string sentence;
	getline(cin , sentence);

	size_t found = sentence.find(" . ");

	if (found != string::npos)
		cout << "OK" << endl;
	else
		cout << "not OK" << endl;

	return 0;
}
//-------------------------------------------
