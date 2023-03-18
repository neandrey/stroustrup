#include "std_lib_facilities.h"

int vect_to_int(vector<int> v_numb);
//---------------------------------------
int main(int argc, char const *argv[])
{
    const int lim_number = 4;
    vector<int> v_numb;
    char ch;
    int res = 0;
    int thousands, hundred, tens, ones;
    thousands = hundred = tens = ones = 0;


    cout << "Введите число от 1 до 4 цифр, для окончания ввода ; (123;): ";
    for(size_t i = 0; i != lim_number; ++i){
            cin >> ch;
            if(ch == ';')
                break;
            v_numb.push_back(ch - '0');
    }

    for(size_t i = 0; i != v_numb.size(); ++i){
        switch (v_numb.size()-i-1)
        {
        case 0:
            ones = v_numb[i]; 
            break;
        case 1:
            tens= v_numb[i];
            break;
        case 2:
            hundred = v_numb[i];
            break;
        case 3:
            thousands = v_numb[i];
            break;
        
        default:
            break;
        }
    }

    
    cout <<  vect_to_int(v_numb) << " - это ";  
    if(thousands) cout << thousands << " тысяча " << ' ';
    if(hundred) cout << hundred << " сотни " << ' ';
    if(tens) cout << tens << " десятков " << ' ';
    if(ones) cout << ones << " единиц " << endl;

    return 0;
}
//------------------------------------------------
int vect_to_int(vector<int> v_numb){
    int res = 0;
    for(size_t i = 0; i != v_numb.size(); ++i)
            res += v_numb[i] * pow(10, v_numb.size()-1-i);

    return res;
}

