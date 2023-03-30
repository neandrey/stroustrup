#ifndef PATRON_H
#define PATRON_H
#include "std_lib_facilities.h"

namespace My_Library{
class Patron{
public:
    Patron(string name, int number);
    string get_name() const { return name; }
    int get_number() const { return number; }
    double get_payment() const {return payment; }
    void set_payment(double p) { payment = p; }
    bool is_payment();
private:
    string name;
    int number;
    double payment;
};

ostream &operator<<(ostream &os, const Patron &pp);
bool operator==(const Patron &p1, const Patron &p2);
bool operator!=(const Patron &p1, const Patron &p2);
}
#endif

