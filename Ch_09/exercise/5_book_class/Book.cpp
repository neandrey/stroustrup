#include "Book.h"

namespace My_Library{
Book::Book(string name_book, string author, string isbn, Genre genre)
    : name_book(name_book), author(author), isbn(isbn), genre(genre){

        if(!check_isbn(isbn)) throw Invalid{};
    }

//------------------------------------------------------------
bool check_isbn(string isbn){
/* проверка номера isbn
    n-n-n-x - формат номера
    n - целое число
    x - цифра или буква
*/
    const int numb_of_seq_int = 3; //кол-во групп целых чисел в isbn 
    vector<string> v_isbn;
    string temp;

    for(size_t i = 0; i != isbn.size(); ++i){

        if(isbn[i] == '-' ){
            v_isbn.push_back(temp);
            temp.empty();
            ++i;
        }
        temp += isbn[i];
    }
    v_isbn.push_back(temp);

    if(v_isbn.size() != 4)
         return false;

    for(size_t i = 0; i != v_isbn.size(); ++i)
        for(auto c : v_isbn[i]){
            if(!isdigit(c) and i < numb_of_seq_int)
                return false;
            if(!isalnum(c) and i == numb_of_seq_int)
                return false;
        }

    return true;
}
//-----------------------------------------------------------------
bool operator==(const Book &b1, const Book &b2){

    return b1.get_isbn() == b2.get_isbn();
}
//------------------------------------------------------------------
bool operator!=(const Book &b1, const Book &b2){

    return !(b1 == b2);
}
//------------------------------------------------------------------
ostream &operator<<(ostream &os, const Book &b){
    os << b.get_name() << " " << b.get_author() << " " << b.get_isbn();
    return os; 

}
}
