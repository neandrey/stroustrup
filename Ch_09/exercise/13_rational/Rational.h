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
private:
    int numerator;
    int denominator;
};

double convert(const Rational &rr);
Rational operator+(const Rational &r1, const Rational &r2);
Rational operator*(const Rational &r1, const Rational &r2);
Rational operator-(const Rational &r1, const Rational &r2);
Rational operator/(const Rational &r1, const Rational &r2);
ostream &operator<<(ostream &os, const Rational &rr);

#endif