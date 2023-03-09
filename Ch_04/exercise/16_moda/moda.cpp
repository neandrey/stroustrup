//moda
#include "std_lib_facilities.h"

int main(){

	vector<int> v_numb;
	int count = 1, max = 0, numb;

	for (int temp; cin >> temp; )
		v_numb.push_back(temp);

	sort(v_numb);

	for (auto it = v_numb.cbegin(); it != v_numb.cend(); ++it) {
		if (*it == *(it+1))
			++count;
		else {
			if (count >= max){
				max = count;
				numb = *it;
			}
			count = 1;
		}
	}

	cout << "Moda is: " << numb << endl;

	return 0;
}
//--------------------------
