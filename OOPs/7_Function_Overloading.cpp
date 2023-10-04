// -------------------------------------------- Function Overloading  --------------------------------------------
//  its a Compile-Time Polymorphism 
// * Functions with same name  differ in return type , no of parameters or type of parameters
#include<iostream>
using namespace std;

class A{
    public:
        void Add(int x , int y){
            cout<<" Sum = "<< x + y<<endl;
        }
        void Add( double x , double y){
             cout<<" Sum = "<< x + y<<endl;
        }
       /*
        int Add(int x , int y){             // ERROR cuz just changed return type and not parameters
            cout<<" Sum = "<< x + y<<endl;
        }
        */ 
//  Default Arguments
        void product( int x , int y , int z=1, int w=1){
            cout<<"Product is "<<x*y*z*w<< endl;
        }
};

int main(){
    A obj;
    obj.Add(10.0,20.0);
    obj.product(10,12);
}