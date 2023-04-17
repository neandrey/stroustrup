#include "std_lib_facilities.h"

class B1{
public:
    virtual void pvf() const = 0; // чисто виртуальная функция.
    virtual void vf() const {cout << "B1::vf()";} 
    void f() const {cout << "B1::f()";}
};

class D1 : public B1{
public:
    //Если не реализовать чисто виртуальную функцию - код не скомпилируется.
    void pvf() const override {
        cout << "Hello world";
    }
    //Можем перекрыть виртуальную функцию
    void vf() const override {
        cout << "D1::vf()";
    }
    //будет происходить вызов локальной функции f().
    void f() const{
        cout << "D1::f()";
    }
    /*
    не скомпилируется так как f() не виртуальная функция.
    void f() const override {
        cout << "D1::f()";
    }
    */
};

class D2 : public D1{
public:
    //Перекрываем чисто виртуальную функцию.
    void pvf() const override {
        cout << "Good bye";
    }
};

int main(){

    //Объект класса B1 не может быть создан, т.к. содержит чисто виртуальную функцию.
    /*
    B1 b1;
    b1.vf();
    cout << endl;
    b1.f();
    cout << endl;
    */

    D1 d1;
    d1.vf();
    cout << endl;
    d1.f();
    cout << endl;
    d1.pvf();
    cout << endl;

    B1& b1Link = d1;
    b1Link.f();
    cout << endl;
    b1Link.vf();
    cout << endl;
    b1Link.pvf();
    cout << endl;

    D2 d2;
    d2.vf();
    cout << endl;
    d2.f();
    cout << endl;
    d2.pvf();
    cout << endl;

    cout << endl;

    return 0;
}