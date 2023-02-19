#include "std_lib_facilities.h"

void change(double&, double&);
//-------------------------
int main(){

	double vmin, vmax, temp;
	vmin = vmax = 0;

	while (cin >> temp){
		
		if (temp < vmin){
			vmin = temp;
			cout << "Наименьшее среди введенных" << endl;
		}

		if (temp > vmax){
			cout << "Наибольшее среди введенных" << endl;
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
		

