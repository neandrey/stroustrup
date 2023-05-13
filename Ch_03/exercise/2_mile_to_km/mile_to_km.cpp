//преобразование миль в км.
#include "std_lib_facilities.h"

int main(){
	const double MILE_TO_KM = 1.609;
	cout << "Введите количестов миль: ";
	double mile = 0;
	cin >> mile;
	cout << "В веденных " << mile << " милях: " 
		<< mile * MILE_TO_KM << " километров.\n";
	
	return 0;
}
