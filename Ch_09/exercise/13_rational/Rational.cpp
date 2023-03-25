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
        reduction(numeration, denominator);
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
Rational &Rational::reduction(int num, int den){
    
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