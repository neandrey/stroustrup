#include "std_lib_facilities.h"
#include "Chrono.h"

using namespace Chrono;
int main(int argc, char const *argv[])
{
    Date today{1963, Month::may, 19};
    Date tomorrow(today);
    tomorrow.add_day(1);
    cout << today << ' ' << tomorrow << endl;

    return 0;
}

