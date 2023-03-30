//#include "/std_lib_facilities.h"
#include "Book.h"
#include "Patron.h" 
#include "Chrono.h" 

namespace My_Library{

struct Transaction{
    Book book;
    Patron patron;
    Chrono::Date date;
    Transaction(Book book, Patron patron, Chrono::Date date):
        book(book), patron(patron), date(date)
        {}
};

class Library{
public:
    class Invalid{};
    void add_patron(Patron p) { v_patron.push_back(p); }
    void add_book(Book b) {v_book.push_back(b); }
    void take_a_book(const Book b, const Patron p);

private:
    bool find_book(Book b);
    bool find_patron(Patron p);
    vector<Book> v_book;
    vector<Patron> v_patron;
    vector<Transaction> v_transactions;
};
}