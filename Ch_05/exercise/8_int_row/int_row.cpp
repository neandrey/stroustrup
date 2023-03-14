//int_row
#include "std_lib_facilities.h"


//--------------------------------------------
int main(){
	
	int n, sum = 0;
	vector<int> i_val;	
	string s_val;
	cout << "Введите количество суммируемых значений: ";
	cin >> n;

	cout << "Введите несколько целых чисел (| для окончания ввода): ";
	for(int temp; cin >> temp; )
		i_val.push_back(temp);

	if(i_val.size() < n)
		error("Выход за границы вектора!");
	else
		for (size_t i = 0; i != n; ++i){
			sum += i_val[i]; 
			if(i+1 == n)
				s_val += to_string(i_val[i]);
			else
				s_val += to_string(i_val[i]) + ' ';
		}
		
	cout << "Сумма первых " << n << " чисел (" << s_val << ") равна " << sum;
	cout << endl;	
		
	return 0;
}
