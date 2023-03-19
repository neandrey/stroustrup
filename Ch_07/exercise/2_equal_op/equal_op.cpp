#include "std_lib_facilities.h"

const char number = '8';
const char quit = 'q';
const char print = ';';
const string prompt = "> ";
const string result = "= ";
const char name = 'a';
const char let = 'L';
const string declkey = "let";


class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    string name;

    Token(char ch)    // make a Token from a char
        :kind(ch) { }
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
    Token(char ch, string n)
        :kind{ch}, name{n} { }
};
//-----------------------------------------------------------------------------
class Token_stream {
public:
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void putback(Token t);    // put a Token back
    void ignore(char c);
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};
//------------------------------------------------------------------------------
void Token_stream::ignore(char c){

    if(full && c==buffer.kind){
        full = false;
        return;
    }
    full = false;
    
    char ch = 0;
    while(cin >> ch)
        if(ch == c) return;
}
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
class Variable {
public:
    string name;
    double value;
    Variable(string s, double d);
};
//----------------------------------------------------------------------------------
Variable::Variable(string s, double d) : name{s}, value{d}
{}
//-----------------------------------------------------------------------------------
vector<Variable> var_table;
Token_stream ts;
double expression();
double term();
double primary();
//----------------------------------------------------------
double get_value(string s){

    for (const Variable &v: var_table)
        if(v.name == s)
            return v.value;
    error("get: Неопределенная переменная", s);
}
//--------------------------------------------------------
double set_value(string s, double d){
    
    for(Variable &v : var_table)
        if(v.name == s){
            v.value = d;
            return d;
        }
    error("set: Неопределенная переменная", s);
}
//----------------------------------------------------------
bool is_declared(string var){
    
    for (const Variable &v : var_table)
        if(v.name == var)
            return true;

    return false;
}
//-------------------------------------------------------------
double define_name(string var, double val){

    if(is_declared(var))
        error(var, " повторное объявление");
    var_table.push_back(Variable(var, val));
    return val;
}
//-----------------------------------------------------------
double declaration(){

    Token t = ts.get();
    if(t.kind != name)
        error("в объявлении ожидается имя переменной");
    string var_name = t.name;

    Token t2 = ts.get();
    if(t2.kind != '=')
        error("пропущен символ = в объявлении ", var_name);
    
    double d = expression();
    define_name(var_name, d);
    return d;
}
//--------------------------------------------------------------------------------
double statement(){
    Token t = ts.get();
    switch (t.kind)
    {
    case let:
        return declaration();
    default:
        ts.putback(t);
        return expression();
    }
}
//---------------------------------------------------------------------------------
void clean_up_mess(){
    ts.ignore(print);
}
//--------------------------------------------------------------------------------
void calculate(){
    while(cin)
    try{
        cout << prompt;
        Token t = ts.get();
        while(t.kind == print) t = ts.get();;
        if (t.kind == quit){
            return;
        }
        ts.putback(t);
        cout << result <<  statement() << endl;
    }
    catch (exception& e){
        cerr << e.what() << endl;
        clean_up_mess();
    }
}
//---------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    define_name("pi", 3.1415926535);
    define_name("e", 2.7182818284);

    try{
        calculate(); 
        keep_window_open();
        return 0;
    }catch(exception &e){
        cerr << e.what() << endl;
        keep_window_open("~~");
                return 1;
    }catch(...){
        cerr<<"исключение" << endl;
            return 2;
    }
    
    return 0;
}
//-------------------------------------------------
double expression() {
    double left = term();
    Token t = ts.get();
    while (true) {
        switch(t.kind) {
        case '+':
            left += term();
            t = ts.get();
            break;
        case '-':
            left -= term();
            t = ts.get();
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
//---------------------------------------------------
double term() {
    double left = primary();
    Token t = ts.get();
    while(true) {
        switch(t.kind) {
        case '*':
            left *= primary();
            t = ts.get();
            break;
        case '/':
        {
            double d = primary();
            if (d == 0)
                error("деление на нуль.");
            left /= d;
            t = ts.get();
            break;
        }
        case '%':
        {
            int i1 = narrow_cast<int>(left);
            int i2 = narrow_cast<int>(primary());
            if(i2 == 0) error("%: деление на нуль");
            left = i1 % i2;
            t = ts.get();
        }
            break;
        default:
            ts.putback(t);
            return left;
        }
    }
}
//------------------------------------------
double primary(){
    Token t = ts.get();
    switch(t.kind) {
        case '(':
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')')
                error("требуется ')'");
            return d;
        }
        case number:
            return t.value;
        case name:
        {
            Token t2 = ts.get();
            if(t2.kind == '=')
                return set_value(t.name, expression());
            else{
                ts.putback(t2);
                return get_value(t.name);
            }

        }
        case '-':
            return -primary();
        case '+':
            return primary();
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
    case print:// for "print"
    case quit:    // for "quit"
    case '(': 
    case ')': 
    case '+': 
    case '-': 
    case '*': 
    case '/':
    case '%':
    case '=':
        return Token{ch};        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token{number, val};   // let number represent "a number"
    }
    default:
        if(isalpha(ch) or ch == '_'){
            string s;
            s += ch;
            while(cin.get(ch) && (isalpha(ch) || isdigit(ch)))
                s += ch;
            cin.putback(ch);

            if(s == declkey)
                return Token(let);
            return Token{name, s};
        }
        error("Bad token");
    }
}