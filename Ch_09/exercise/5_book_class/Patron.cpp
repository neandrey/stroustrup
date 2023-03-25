#include "Patron.h"

namespace My_Library{
Patron::Patron(string name, int number)
    : name(name), number(number)
    {}
//-------------------------------------------------------
bool Patron::is_payment(){

    return (payment > 0.0) ? true : false;
}

ostream &operator<<(ostream &os, const Patron &pp){
    os << "имя абонента: " << pp.get_name() << 
        " номер абонимента: " << pp.get_number() << 
        " cумма взноса: " << pp.get_payment();
    return os;
}
//-------------------------------------------------------
bool operator==(const Patron &p1, const Patron &p2){
    if(p1.get_name() == p2.get_name() and
    p1.get_number() == p2.get_number())
    return true;
}
//---------------------------------------------------------
bool operator!=(const Patron &p1, const Patron &p2){
    return !(p1 == p2);
}
}


