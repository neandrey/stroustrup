#include "Name_pairs.h"

using namespace my_namespace;
int main(int argc, char const *argv[])
{
    Name_pairs name; 

    name.read_names();
    name.read_ages();
    name.sort();
    cout << name;
    
    return 0;
}
