#include "std_lib_facilities.h"

const int not_a_reading = -7777;
const int not_a_month = -1;


vector<string> month_input_tbl = {
    "jan", "feb", "mar", "apr", "may", "jun",
    "jul", "aug", "sep", "oct", "nov", "dec" 
};

int month_to_int(string s){
    
    for(size_t i = 0; i < 12; ++i)
        if(month_input_tbl[i] == s)
            return i;
    return -1;
}

vector<string> month_print_tbl = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

string int_to_month(int i)
    // months [0:11]
{
    if (i < 0 || 12 <= i) error("bad month index");
    return month_print_tbl[i];
}

struct Day{
    vector<double> hour{vector<double> (24, not_a_reading)};
};

struct Month{
    int month {not_a_month}; // [0, 11] (0 - январь)
    vector<Day> day {32}; //[1, 31] по одному вектору на день
};

struct Year{
    int year;
    vector<Month> month{12};
};

struct Reading{
    int day;
    int hour;
    double temperature;
};

void end_of_loop(istream &ist, char term, const string &message);
bool is_valid(const Reading &r);
//void print_year(ofstream &ofs, Year &y);

istream &operator>>(istream &is, Reading &r){
    
    char ch1;
    if(is >> ch1 && ch1 != '('){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    char ch2;
    int d;
    int h;
    double t;
    is >> d >> h >> t >> ch2;
    if(!is || ch2 != ')')
        error("Плохая запись");
    r.day = d;
    r.hour = h;
    r.temperature = t;
    return is;
}

istream &operator>>(istream &is, Month &m){

    char ch = 0;
    if(is >> ch && ch != '{'){
        is.unget();
        is.clear(ios_base::failbit);
        return is;
    }

    string month_marker;
    string mm;
    is >> month_marker >> mm;
    if(!is || month_marker != "month")
        error("Неверное начало Month");
    m.month = month_to_int(mm);

    Reading r;
    int duplicates = 0;
    int invalids = 0;
    for(Reading r; is >> r; ){
        if(is_valid(r)){
            if(m.day[r.day].hour[r.hour] != not_a_reading)
                ++duplicates;
            m.day[r.day].hour[r.hour] = r.temperature;
        }
        else
            ++invalids;
    }
    if(invalids)
        error("Неверные данные в Month, всего", invalids);
    if(duplicates)
        error("Повторяющиеся показания в Month, всего ", duplicates);
    end_of_loop(is, '}', "Неправильный конец Month");
    return is;
}

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading &r){
    
    if(r.day < 1 || r.day > 31) return false;
    if(r.hour < 0 || r.hour > 23) return false;
    if(r.temperature < implausible_min || r.temperature > implausible_max) return false;
    
    return true;
}


istream &operator>>(istream &is, Year &y){
    
    char ch;
    is >> ch;
    if(ch !='{'){
        is.unget();
        is.clear(ios::failbit);
        return is;
    }

    string year_marker;
    int yy;
    is >> year_marker >> yy;
    if(!is || year_marker != "year")
        error("Неправильное начало Year");
    y.year = yy;
    while(true){
        Month m;
        if(!(is >> m)) break;
        y.month[m.month] = m;
    }
    
    end_of_loop(is, '}', "Неправильный конец Year");
    return is;
}

//--------------------------------------------------
//end_of_loop
void end_of_loop(istream &ist, char term, const string &message){
    
    if(ist.fail()){
        ist.clear();
        char ch;
        if(ist >> ch && ch == term) return; //все хорошо в конце
        error(message);

    }
}
//---------------------------------------------------
//print_year
void print_year(ofstream& ofs, Year y)
    // write year data to destination output stream
{
    ofs << y.year << ":\n";
    for (Month m : y.month)
        if (m.month != not_a_month) {
            ofs << '\t' << int_to_month(m.month) << '\n';

            for (int d = 1; d < m.day.size(); ++d)
                for (int h = 0; h < m.day[d].hour.size(); ++h)

                    if (m.day[d].hour[h] != not_a_reading)
                        ofs << "\t\t" << d << '\t' << h << '\t'
                            << m.day[d].hour[h] << '\n';
        }
}

int main(int argc, char const *argv[])
{
    cout << "Введите имя входного файла\n";
    string iname;
    cin >> iname;
    ifstream ifs{iname};
    if(!ifs) error("Невозможно открыть входной файл ", iname);
    
    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    cout << "Введите имя выходного файла\n";
    string oname;
    cin >> oname;
    ofstream ofs{oname};
    if(!ofs) error("Невозможно открыть выходной файл ", oname);

    vector<Year> ys;
    while(true){
        Year y;
        if(!(ifs>>y)) break;
        ys.push_back(y);
    }
    cout << "Считано " << ys.size() << " годичных записей\n";
    for(Year &y : ys)
        print_year(ofs, y);
    return 0;
}