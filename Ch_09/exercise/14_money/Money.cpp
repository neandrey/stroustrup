#include "Money.h"

namespace my_money{

ostream &operator<<(ostream &os, Money &m)
{
    os << "$ " <<  m.convert_to_dollar();
    return os;
}
//------------------------------------------
istream &operator>>(istream &is, Money &m)
{
    double in_val;
    is >> in_val;
    if(!is){
        error("Значение должно быть double");
    } 
    m = Money{in_val};

    return is; 
}
//-------------------------------------------
Money::Money()
{
    set_money(0);
}
//-------------------------------------------
Money::Money(double m)
{
    if(m < 0) throw Invalid();
    size_t int_val = rounding(m);
    set_money(convert_to_cent(int_val));
}
//-------------------------------------------
size_t Money::rounding(double n)
{
    int integer = static_cast<int>(n);
    double fractional = n - integer;
    if(fractional >= round_value)
        ++integer;
    
    return integer;
}
//-----------------------------------
long Money::convert_to_cent(size_t n)
{
    return n * 100;
}
//-----------------------------------------
double Money::convert_to_dollar()
{
    return get_money() / cent_in_dollar;
}
//-------------------------------------------
}