//считываем символы в переменную string. 
#include "std_lib_facilities.h" 

int main(){

    string s1;

    for (char temp; cin >> temp; ){
        if(temp == '!')
            break;
        s1.push_back(temp);
    }

    cout << s1 << endl;

    return 0;
}
