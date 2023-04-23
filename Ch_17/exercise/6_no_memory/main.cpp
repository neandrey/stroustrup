//переполнение выделенной памяти из кучи. 
#include "std_lib_facilities.h" 

int main(){

    size_t megabyte = 1048576;
    size_t i{0}, max{100};

    //Arch выжирает всю свободную память после чего приходится делать reboot
    while(true){

        char* dd = new char[megabyte * max];
        cout << "Количество выделенной памяти: " << (i+=max) 
            << " Mбайт" << endl;
    }

    return 0;
}

