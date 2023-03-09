//moda_string
#include "std_lib_facilities.h"

int main(){

	vector<string> str;
	string s_res;
	int count = 1, max = 0;

	for (string temp; cin >> temp; )
		str.push_back(temp);

	sort(str);
	cout << "min value: " << *(str.cbegin()) << endl;
	cout << "max value: " << *(--str.cend()) << endl;

	for (auto it = str.cbegin(); it != str.cend(); ++it) {
		if (*it == *(it+1))
			++count;
		else {
			if (count >= max){
				max = count;
				s_res = *it;
			}
			count = 1;
		}
	}

	cout << "Moda is: " << s_res << endl;

	return 0;
}
//--------------------------
