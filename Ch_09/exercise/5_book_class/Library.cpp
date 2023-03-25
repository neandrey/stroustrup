#include "Library.h"

namespace My_Library{

void Library::take_a_book(Book b, Patron p){
//Проверяем может ли взять пользователь книгу.

    //проверка книги
    if(!find_book(b))
        throw Invalid{};

    //проверка имени
    if(!find_patron(p))
        throw Invalid{};

    //проверка оплаты
    if(!p.is_payment())
        throw Invalid{};

    Transaction tt{b, p, {1963, Chrono::Month::may, 19}};
    v_transactions.push_back(tt);

}
//---------------------------------------------
bool Library::find_book(Book b){
    for(auto book : v_book)
        if(book == b)
            return true;
    return false;
}
//-------------------------------------------
bool Library::find_patron(Patron p){
    for(auto parton : v_patron)
        if(parton == p)
            return true;
    return false;
}
}