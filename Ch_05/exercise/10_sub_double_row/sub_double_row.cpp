//sub_double_row
#include "std_lib_facilities.h"


//--------------------------------------------
int main(){
	
	vector<double> d_val;	
	vector<double> diff;
	cout << "Введите несколько чисел с плавающей запятой (| для окончания ввода): ";
	for(double temp; cin >> temp; ){
		d_val.push_back(temp);
	}

	for (size_t i = 0; i != d_val.size()-1; ++i){
		diff.push_back(d_val[i] - d_val[i+1]);
	}
		
	for(auto d : diff)
		cout << d << ' ';
	cout << endl;	
		
	return 0;
}
