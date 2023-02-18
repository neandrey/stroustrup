#include "std_lib_facilities.h"

void change(double&, double&);
//-------------------------
int main(){

	double val1, val2;

	while (cin >> val1 >> val2){
		
		if (val1 < val2)
			change(val1, val2);

		if (val1 == val2)
			cout << "Числа равны" << endl;

		if (abs(val1 - val2) < 0.01)
			cout << "Числа почти равны" << endl;
		
		else{
				cout << "Наименьшее значение равно: " << val2 << endl;
				cout << "Наибольшее значение равно: " << val1 << endl;	
		}
	}

	return 0;
}
//--------------------------
void change(double& v1, double& v2){
	double temp = v2;
	v2 = v1;
	v1 = temp;
}
		

