#include "std_lib_facilities.h"

int main(){

	vector<double> temps;

	for (double temp; cin >> temp;)
		temps.push_back(temp);

	cout << "Размер последовательность: " << temps.size() << endl;

	//медианная температура
	
	sort(temps);
	double mediana = 0;
	int middle = temps.size() / 2;
	if (temps.size()){
		if (temps.size() % 2 == 0)
			mediana = (temps[middle/2] + temps[middle-1]) / 2; 
		else
			mediana = temps[temps.size()/2];
	}
	cout << "Медианная температура: "
		<< mediana  << endl;

	return 0;
}
