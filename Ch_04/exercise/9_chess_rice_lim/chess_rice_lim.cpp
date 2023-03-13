#include "std_lib_facilities.h"

int main(){

	int ival = 2147483646;
	cout << ival << endl;
	
	int cell = 1;
	int cell_rice = 1;
	int sum_rice = 0;

	while(sum_rice <= ival){

		cout << "Номер клетки: " << cell << " Количество риса в этой клетки "
			<< cell_rice << " Сумма риса в предыдущих клетках " << sum_rice
			<< endl;

		++cell;
		sum_rice += cell_rice;
		cell_rice *= 2;
	}
	

	return 0;
}
