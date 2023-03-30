#include "std_lib_facilities.h"
#include "Library.h" 

using namespace My_Library;
using namespace Chrono;
int main(int argc, char const *argv[])
{
    Book book1{"Алгебра", "Перельман", "123-138-456-X", Genre::nonfiction};
    Book book2{"C++", "Павловская", "123-456-78910-GR1", Genre::nonfiction};
    Book book3{"C++", "Павловская", "123-456-78910-GR1", Genre::nonfiction};

    cout << book1 << endl;
    cout << book2 << endl;
    cout << book3 << endl;

    if(book3 == book2)
        cout << "isbn equal" << endl;
    else
        cout << "isbn not equal" << endl; 

    Patron p1{"Сергей", 1201};
    Patron p2{"Алексей", 1101};

    cout << p1 << endl;
    cout << p2 << endl;

//  проверка високосного года.
    while(true){
        int year;
        cout << "Введите год: ";
        cin >> year;

        if(leapyear(year))
            cout << "Високосный год " << endl;
        else
            cout << "Год не високосный" << endl;
    }
    

    Library ll;

    ll.add_book(book1);
    ll.add_book(book2);
    ll.add_book(book3);
    ll.add_patron(p1);
    ll.add_patron(p2);
    

    return 0;
}
