#ifndef RATIONAL_H
#define RATIONAL_H
#include "std_lib_facilities.h"

class Rational{
public:
    class Invalid{};
    Rational();
    Rational(int numerator, int denominator);
    int get_numerator() const { return numerator; }
    int get_denominator() const { return denominator; }
    void set_numerator(int n) { numerator = n; }
    void set_denominator(int d) { denominator = d; }   
    Rational &operator=(const Rational &r1);
    Rational &reduction(Rational &rr);
    Rational &reduction(int num, int den);
    Rational &swap_rational(Rational &rr);
private:
    int numerator;
    int denominator;

};

double convert(const Rational &rr);
int find_noz(const Rational &r1, const Rational &r2);
int find_multiplier(const Rational &rr, int noz);
Rational operator+(const Rational &r1, const Rational &r2);
Rational operator*(const Rational &r1, const Rational &r2);
Rational operator-(const Rational &r1, const Rational &r2);
Rational operator/(const Rational &r1, const Rational &r2);
ostream &operator<<(ostream &os, const Rational &rr);
bool operator==(const Rational &r1, const Rational &r2);
bool operator!=(const Rational &r1, const Rational &r2);

#endif