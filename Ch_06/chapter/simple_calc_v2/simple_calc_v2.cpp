#include "std_lib_facilities.h"

int main(int argc, char const *argv[])
{
    cout << "Введите выражение (разрешены +, -, * и /)\n";
    cout << "Добавте x к концу выражения (1+2*3x): ";
    int lval = 0;
    int rval;
    cin >> lval;

    if(!cin){
        error("Нет первого операнда");
    }

    for(char op; cin >> op; ){
        if(op != 'x'){
            cin >> rval;
        }
        if(!cin){
            error("Нет второго операнда");
        }
        switch(op){
            case '+':
                lval += rval;
                break;

            case '-':
                lval -= rval;
                break;

            case '*':
                lval *= rval;
                break;

            case '/':
                lval /= rval;
                break;

            default:
                cout << "Результат: " << lval << endl;
                return 0;
        }
    }
    error("Неверное выражение");
    return 0;
}