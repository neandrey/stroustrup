//sqr_equation ax2 + b + c = 0
#include "std_lib_facilities.h"

void sqr_equ(double a, double b, double c){
	
	double D = b*b - 4*a*c;
	double x1, x2;

	if (D > 0){
		x1 = (-b + sqrt(D)) / (2*a); 
		x2 = (-b - sqrt(D)) / (2*a); 
		cout << "x1 = " << x1 << "; x2 = " << x2 << endl;
	}else if (D = 0){
		x1 = -b / (2*a);
		cout << "x1,2 = " << x1 << endl;
	}else
		cout << "Уравнение не имеет корней." << endl;
}
//--------------------------------------------
int main(){

	double a, b, c;
	cout << "input a, b, c: ";
	cin >> a >> b >> c;
	sqr_equ(a, b, c);

	
	return 0;
}