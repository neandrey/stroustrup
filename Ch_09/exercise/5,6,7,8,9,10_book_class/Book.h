#ifndef BOOK_H
#define BOOK_H
#include "std_lib_facilities.h"

namespace My_Library{
enum class Genre {
    fiction = 1, nonfiction, pereodical, biography, children
};

class Book{
public:
    class Invalid{};
    Book (string name_book, string author, string isbn, Genre genre);
    string get_name() const { return name_book; }
    string get_author() const { return author; }
    string get_isbn() const { return isbn; }
    Genre get_genre() const { return genre; }

    void set_hand() { onHand = true; }
    void reset_hand() { onHand = false; }

private:
    string name_book;
    string author;
    string isbn;
    Genre genre;
    bool onHand = false;
};

bool check_isbn(string isbn);

ostream &operator<<(ostream &os, const Book &b);
bool operator==(const Book &b1, const Book &b2);
bool operator!=(const Book &b1, const Book &b2);
}
#endif