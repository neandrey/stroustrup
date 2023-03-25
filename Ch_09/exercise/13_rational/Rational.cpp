#include "Rational.h"

//--------------------------------------------------------
Rational::Rational()
    :numerator{1}, denominator{1}
    {}
//---------------------------------------------------------
Rational::Rational(int numeration, int denominator)
    :numerator{numeration}, denominator{denominator}
    {
        if(!denominator) throw Invalid();
    }
//----------------------------------------------------------
double convert(const Rational &rr){
    return rr.get_numerator() / static_cast<double>(rr.get_denominator());
}
//---------------------------------------------------------------------------
Rational operator+(const Rational &r1, const Rational &r2){

    Rational temp;
    if(r1.get_denominator() == r2.get_denominator()){
        temp.set_denominator(r1.get_denominator());
        temp.set_numerator(r1.get_numerator() + r2.get_numerator()); 
    }

    temp.reduction(temp);

    return temp;
}
//-----------------------------------------------------------------------------
Rational operator-(const Rational &r1, const Rational &r2){
    //...
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
    //...
}
//-----------------------------------------------------------------------------
ostream &operator<<(ostream &os, const Rational &rr){

    os << rr.get_numerator() << "/" << rr.get_denominator() << endl;
    return os;
}
//--------------------------------------------------------------------------------
Rational &Rational::operator=(const Rational &r1){

    if(this == &r1)
        return *this;

    this->numerator = r1.get_numerator();
    this->denominator = r1.get_denominator();

    return *this;
}
//---------------------------------------------------------------------------------
Rational &Rational::reduction(Rational &rr){

    size_t max_val = min(rr.numerator, rr.denominator);

    for(size_t i = 1; i <= max_val; ++i){
        if(rr.numerator % i == 0 and rr.denominator % i == 0){
            rr.numerator /= i;
            rr.denominator /= i;
        }
    }

    return rr;
}