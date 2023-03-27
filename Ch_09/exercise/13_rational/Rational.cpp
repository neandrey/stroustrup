#include "Rational.h"

//--------------------------------------------------------
Rational::Rational()
    :numerator{1}, denominator{1}
    {}
//---------------------------------------------------------
Rational::Rational(int numeration, int denominator)
    :numerator{numeration}, denominator{denominator}
    {
        if(!denominator and denominator < 0) throw Invalid();
        reduction(numeration, denominator);
    }
//----------------------------------------------------------
double convert(const Rational &rr){
    return rr.get_numerator() / static_cast<double>(rr.get_denominator());
}
//---------------------------------------------------------------------------
Rational operator+(const Rational &r1, const Rational &r2){

    Rational temp;
    size_t noz = find_noz(r1, r2);
    size_t first_factor = find_multiplier(r1, noz);
    size_t second_factor = find_multiplier(r2, noz);
    temp.set_numerator(first_factor * r1.get_numerator() + second_factor * r2.get_numerator());
    temp.set_denominator(noz);
    temp.reduction(temp);

    return temp;
}
//-----------------------------------------------------------------------------
Rational operator-(const Rational &r1, const Rational &r2){

    Rational temp;
    size_t noz = find_noz(r1, r2);
    size_t first_factor = find_multiplier(r1, noz);
    size_t second_factor = find_multiplier(r2, noz);
    temp.set_numerator(first_factor * r1.get_numerator() - second_factor * r2.get_numerator());
    temp.set_denominator(noz);
    temp.reduction(temp);

    return temp;   
}
//-----------------------------------------------------------------------------
Rational operator*(const Rational &r1, const Rational &r2){
    
    Rational temp; 
    temp.set_numerator(r1.get_numerator() * r2.get_numerator());
    temp.set_denominator(r1.get_denominator() * r2.get_denominator());
    temp.reduction(temp);

    return temp;
}
//-----------------------------------------------------------------------------
Rational operator/(const Rational &r1, const Rational &r2){
    
}
//-----------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Rational &rr){

    os << rr.get_numerator() << "/" << rr.get_denominator() << endl;
    return os;
}
//--------------------------------------------------------------------------------
Rational &Rational::operator=(const Rational &rr){

    if(this == &rr)
        return *this;

    this->numerator = rr.get_numerator();
    this->denominator = rr.get_denominator();

    return *this;
}
//---------------------------------------------------------------------------------
Rational &Rational::reduction(int num, int den){
    
    num = abs(num);
    size_t min_val = min(num, den);

    for(size_t i = 1; i <= min_val; ++i){
        if(num % i == 0 and den % i == 0){
            this->numerator /= i;
            this->denominator /= i;
        }
    }
    return *this;
}
//----------------------------------------------------------------------------------
Rational &Rational::reduction(Rational &rr){

    return reduction(rr.numerator, rr.denominator);
}
//----------------------------------------------------------------------------------
int find_noz(const Rational &r1, const Rational &r2){
//находим НОЗ
    int den1 = r1.get_denominator();
    int den2 = r2.get_denominator();
    size_t i = 1;

    while(true){
        int temp = den1 * i;
        if(temp % den2 == 0 and temp % den2 == 0)
            return temp;
        ++i;
    } 
}
//------------------------------------------------------------------
int find_multiplier(const Rational &rr, int noz){

    return noz / rr.get_denominator();
}
//------------------------------------------------------------------