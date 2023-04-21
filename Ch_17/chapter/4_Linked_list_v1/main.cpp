// указатели и ссылки
#include "std_lib_facilities.h" 

struct Link{
    string value;
    Link* prev;
    Link* succ;
    //constructor
    Link(const string& v, Link* p = nullptr, Link* s = nullptr)
    : value{v}, prev{p}, succ{s}
    {}
};

Link* insert(Link* p, Link* n);
Link* erase(Link* p);
Link* find(Link* p, const string& s);
Link* advance(Link* p, int n);
void print_all(Link* p);

int main(){

    Link* norse_gods = new Link{"Thor"};
    norse_gods = insert(norse_gods, new Link{"Odin"});
    norse_gods = insert(norse_gods, new Link{"Zeus"});
    norse_gods = insert(norse_gods, new Link{"Freia"});

    Link* greek_gods = new Link{"Hera"};
    greek_gods = insert(greek_gods, new Link{"Athena"});
    greek_gods = insert(greek_gods, new Link{"Mars"});
    greek_gods = insert(greek_gods, new Link{"Posedon"});

    Link* p = find(greek_gods, "Mars");
    if(p)
        p->value = "Ares";
    
    p = find(norse_gods, "Zeus");
    if(p){
        if(p==norse_gods) norse_gods = p->succ;
        erase(p);
        greek_gods = insert(greek_gods, p);
    }

    print_all(norse_gods);
    cout << endl;

    print_all(greek_gods);
    cout << endl;


    return 0;
}
//----insert------------------------------------------------
Link* insert(Link* p, Link* n){
    
    if(n == nullptr) return p;
    if(p == nullptr) return n;

    n->succ = p;
    if(p->prev) 
        p->prev->succ = n;
    
    n->prev = p->prev;
    p->prev = n;
    return n;
}
//-----add--------------------------------------------------
Link* add(Link* p, Link* n){
    //---
}
//-----erase------------------------------------------------
Link* erase(Link* p){

    if(p == nullptr) return nullptr;
    if(p->succ) p->succ->prev = p->prev;
    if(p->prev) p->prev->succ = p->succ;
    return p->succ;
}
//-----find--------------------------------------------------
Link* find(Link* p, const string& s){

    while(p){
        if(p->value == s) return p;
        p = p->succ;
    }
    return nullptr;
}
//----advance-------------------------------------------------
Link* advance(Link* p, int n){

    if(p == nullptr) return nullptr;
    if(0 < n){
        while(n--){
            if(p -> succ == nullptr) return nullptr;
            p = p->succ;
        }
    }
    else if(n < 0){
        while(n++){
            if(p->prev == nullptr) return nullptr;
            p = p->prev;
        }
    }
    return p;
}
//----print_all-----------------------------------------------
void print_all(Link* p){

    cout << "{ ";
    while(p){
        cout << p->value;
        if(p=p->succ) cout << ", ";
    }
    cout << " }";
}
//----------------------------------------------------------
