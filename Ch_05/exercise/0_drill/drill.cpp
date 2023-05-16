//cels_to_kelvin
#include "std_lib_facilities.h"

int main(){
    
    try{

        cout << "1.Success!\n"; //Cout << "Success!\n"; 
        cout << "2.Success!\n";
        cout << "3.Success" <<  "!\n"; //cout << "Success" << !\n"
        string success = "4.Success!";
        cout << success << '\n'; 

        string res = "7"; vector<string> v(10); v[5] = res;
        cout << "5.Success!\n";

        vector<int> v1(10); v1[5] = 7; if(v1[5] == 7) cout << "6.Success!\n";

        bool cond = true;
        if(cond) cout << "7.Success!\n"; else cout << "Fail!\n";

        bool c = false; if(!c) cout << "8.Success!\n"; else cout << "Fail!\n";

        string s = "ape"; bool c1 = "fool" > s; if(c1) cout << "9.Success!\n";

        string s1 = "ape"; if(s != "fool") cout << "10.Success!\n";

        string s2 = "ape"; if(s != "fool") cout << "11.Success!\n";

        vector<char> v2(5); for(int i = 0; 0 > v2.size(); ++i); cout << "12.Success!\n";

        vector<char> v3(5); for(int i = 0; i < v.size(); ++i); cout << "13.Success!\n";

        string s3 = "14.Success!\n"; for(int i = 0; i < s3.length(); ++i) cout << s3[i];

        if(true) cout << "15.Success!\n"; else cout << "Fail!\n";

        int x = 2000; int c2 = x; if(c2 == 2000) cout << "16.Success!\n";

        cout << "17.";
        string s4 = "Success!\n"; for(int i = 0; i < 10; ++i) cout << s4[i];

        vector<int> v4(5); for(int i = 0; i < v.size(); ++i); cout << "18.Success!\n";

        int i = 0; int j = 9; while (i < 10) ++i; if(j <= i) cout << "19.Success!\n";
        
        int x1 = 2; double d = 5.0/x1 + 2; if (d == 2 * x1 + 0.5) cout << "20.Success\n";

        cout << "21.";
        string s5 = "Success!\n"; for(int i = 0; i < 10; ++i) cout << s5[i];

        int i1 = 0; int j1 = 0; while(i1 < 10) ++i1; if(j1 < i1) cout << "22.Success!\n";

        int x2 = 4; double d1 = 5.0/(x2-2); if(d1 == x2/2.0+0.5) cout << "23.Success!\n";

        cout << "24.Success!\n";

        return 0;
    }
    catch(exception& e){
        cerr << "Ошибка: " << e.what() << endl;
        return 1;
    }
    catch(...){
        cerr << "Неизвестное исключение\n";
        return 2;
    }
    
}