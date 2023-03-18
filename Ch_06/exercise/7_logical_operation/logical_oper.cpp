#include "std_lib_facilities.h"
/*
! - отрицание
~ - дополнение
& - логическое и
| - логическое или
^ - исключающее или
//-------------------------
!,~ - наивысший приоритет
&
^
| - наименьший приоритет
*/

class Token {
public:
    char kind;        // what kind of token
    int value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

//------------------------------------------------------------------------------

// The constructor just sets full to indicate that the buffer is empty:
Token_stream::Token_stream()
    :full(false), buffer(0)    // no Token in buffer
{
}

//------------------------------------------------------------------------------

// The putback() member function puts its argument back into the Token_stream's buffer:
void Token_stream::putback(Token t)
{
    if (full) error("putback(): буфер заполнен");
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}
//---------------------------------------------------------------------------------
Token_stream ts;
//-----------------------------------------------
int expression();
int term();
int primary();
int high_term();
int high_high_term();
//-----------------------------------------------

int main(int argc, char const *argv[])
{
    int val = 0;
    try{
        while(cin){
            Token t = ts.get();
            if (t.kind == 'q') break;
            if (t.kind == ';')
                cout << "=" << val << '\n';
            else
                ts.putback(t);
            val = expression();
        }
    }catch(exception &e){
        cerr << e.what() << endl;
    }catch(...){
        cerr<<"исключение" << endl;
    }
    
    return 0;
}
//-------------------------------------------------
int expression() {
    int left = term();
    Token t = ts.get();
    while (true) {
        switch(t.kind) {
        case '|':
            left |= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
//---------------------------------------------------
int term() {
    int left = high_term();
    Token t = ts.get();
    while(true) {
        switch(t.kind) {
        case '^':
            left ^= high_term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
//------------------------------------------
int high_term(){
    int left = primary();
    Token t  = ts.get();
    while (true){
        switch (t.kind)
        {
        case '&':
            left &= primary();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
//------------------------------------------
int primary(){
    Token t = ts.get();
    switch(t.kind) {
        case '!':
            return !primary();
        case '~':
            return ~primary();
        case '8':
            return t.value;
        default:
            error("требуется первичное выражение");
    }
}
//--------------------------------------------
Token Token_stream::get()    // read a token from cin
{
    if(full){
        full = false;
        return buffer;
    }

    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
    case '!': case '&': case '~': case '^': case '|':
        return Token{ch};        // let each character represent itself
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token{'8', val};   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}