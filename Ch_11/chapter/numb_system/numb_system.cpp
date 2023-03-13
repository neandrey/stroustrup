#include "std_lib_facilities.h"

int main(int argc, char const *argv[])
{
    //целые числа
    cout << 1234 << "\t(decimal)\n"
        << hex << 1234 << "\t(hexadecimal)\n"
        << oct << 1234 << "\t(octal)\n";

    cout << dec <<  1234 << '\t' << hex << 1234
        << '\t' << oct << 1234 << '\n';
    cout << dec;
    cout << 1234 << '\n';

    //числа с плавающей запятой
    cout << 1234.56789 << "\t\t(по умолчанию)\n"
        << fixed << 1234.56789 << "\t(фиксированный)\n"
        << scientific << 1234.56789 << "\t(научный)\n";

    cout << 1234.56789 << '\n';
    cout << defaultfloat << 1234.56789
        << '\t' << fixed << 1234.56789
        << '\t' << scientific << 1234.56789 << endl;

    cout << defaultfloat << 1.2345678 << endl;

    //поля
    cout << 123456 << '|' << setw(4) << 123456 << '|'
        << setw(8) << 123456 << '|' << 123456 << "|\n";

    return 0;
}
