#include "std_lib_facilities.h"
#include "Point.h"

using namespace my_point;
int main(int argc, char const *argv[])
{
    const int size_points = 7;
    vector<Point> original_points;   
    Point p;

    for(size_t i = 0; i != size_points; ++i){
        cin >> p;
        original_points.push_back(p);
    }

    for(auto p : original_points)
        cout << p << endl;

    return 0;
}
