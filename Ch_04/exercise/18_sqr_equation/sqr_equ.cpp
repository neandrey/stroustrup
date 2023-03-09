//sqr_equation ax2 + b + c = 0
#include "std_lib_facilities.h"

int main(){

	double a, b, c;
	double x1, x2;
	cout << "input a, b, c: ";
	cin >> a >> b >> c;

	double D = b*b - 4*a*c;

	if (D > 0){
		x1 = (-b + sqrt(D)) / (2*a); 
		x2 = (-b - sqrt(D)) / (2*a); 
		cout << "x1 = " << x1 << "; x2 = " << x2 << endl;
	}else if (D = 0){
		x1 = -b / (2*a);
		cout << "x1,2 = " << x1 << endl;
	}else
		cout << "Уравнение не имеет корней." << endl;


	return 0;
}
//--------------------------
