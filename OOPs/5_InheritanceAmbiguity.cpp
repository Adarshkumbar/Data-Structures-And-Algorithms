//          Inheritance Ambiguity
// caused when a Class Inherts Multiple classes with same methods ex: A: show() .. B: Show();

#include<iostream>
using namespace std;

class A{

    public:
        void show(){
            cout<<"THIS IS A "<<endl;
        }
};

class B{
    public:
        void show(){
            cout<<"THIS IS B "<<endl;
        }
};
// class C inherits classes A and B
class C : public A , public B{
    public:

};

int main(){
    C obj;
 //---------------------- Ambiguity ----------------------
    // obj.show();         // error AMBIGOUS cuz present in BOTH A AND C classes

// ---------------------- Resolving Ambiguity ---------------------- using :: operator
    obj.A::show();          // A's show()
    obj.B::show();          // B's show()
}