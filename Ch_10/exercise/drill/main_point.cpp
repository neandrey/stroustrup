#include "std_lib_facilities.h"
#include "Point.h"

using namespace my_point;
int main(int argc, char const *argv[])
{
    const int size_points = 3;
    vector<Point> original_points;   
    Point p;

    for(size_t i = 0; i != size_points; ++i){
        cout << "Введите (x,y): ";
        cin >> p;
        original_points.push_back(p);
    }

    for(auto p : original_points)
        cout << p << endl;
    cout << endl;

    string oname = "point.txt";
    //cin >> oname;
    ofstream ofs{oname};
    if(!ofs) error("Невозможно открыть выходной файл ", oname);

    for(auto p : original_points)
        ofs << p << endl;
    
    vector<Point> processed_point;
    ifstream ifs{oname};
    if(!ifs) error("Невозможно открыть входной файл ", oname);

    ifs.exceptions(ifs.exceptions() | ios_base::badbit);

    while(true){
        Point p;
        if(!(ifs>>p)) break;
        processed_point.push_back(p);
    }

    for(auto p : processed_point)
        cout << p << endl;

    return 0;
}
