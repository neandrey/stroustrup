#include "std_lib_facilities.h"

int main(int argc, char const *argv[])
{
    cout << "Введите имя файла для ввода\n";
    string iname;
    cin >> iname;
    ifstream ifs{iname, ios_base::binary};
    if(!ifs) error("Невозможно открыть входной файл ", iname);

    cout << "Введите имя файла для вывода\n";
    string oname;
    cin >> oname;
    ofstream ofs{oname, ios_base::binary};
    if(!ofs) error("Невозможно открыть выходной файл ", oname);

    vector<int> v;

    for(int x; ifs.read(as_bytes(x), sizeof(int));)
        v.push_back(x);

    for(int x : v)
    ofs.write(as_bytes(x), sizeof(int));

    return 0;
}
