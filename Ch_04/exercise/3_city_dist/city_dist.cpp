#include "std_lib_facilities.h"

int main(){

	vector<double> temps;

	for (double temp; cin >> temp;)
		temps.push_back(temp);

	double sum = 0;
	for (auto it : temps)
		sum += it;

	cout << "Общее расстояние между городами: " << sum << endl;

	sort(temps);

	cout << "Наименьшее расстояние: " << temps[0] << endl;
	cout << "Наибольшее расстояние: " << temps[temps.size()-1] << endl;

	//среднее расстояние между городами
	cout << "Среднее расстояние между городами: " <<  sum / temps.size()
		<< endl;

	return 0;
}
