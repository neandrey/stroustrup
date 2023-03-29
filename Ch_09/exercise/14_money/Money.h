#ifndef MONEY_H
#define MONEY_H
#include "std_lib_facilities.h"

namespace my_money{
class Money{

static constexpr double round_value = 0.5;
static constexpr double cent_in_dollar = 100.0;

public:
    class Invalid{};
    Money();
    Money(double m);
    //Money(double m, );
    long get_money() const { return cent; }
    void set_money(long n) { cent = n; }
    size_t rounding(double n);
    long convert_to_cent(size_t n);
    double convert_to_dollar();

private:
    long cent;
};

ostream &operator<<(ostream &os, Money &m);
istream &operator>>(istream &is, Money &m);

}
#endif