// -------------------------------------------- Operator Overloading  --------------------------------------------
//  its a Compile-Time Polymorphism 
// * Operators like + - & , | == =  ` ~ () delete new ..... will be overloaded
// Syntax :
//          return_type operator operator_symbol(){ //code to overload }
#include<iostream>
using namespace std;
//  1
class Overloader{  // + operator overloading
    public:
    int a ;
    //  Overloading + operator to subtract instead of Add
    void operator +( Overloader & obj){
        int val1 = this -> a;           // this is 1st operand   //// i.e obj1 + obj2 
        int val2 = obj.a;               // this is 2nd operand 
        cout<<"Result is "<< val2 - val1 <<endl;
    }
};
// 2
class BraceOverloading{  // this class overloads () operators ---->
    public:
        void operator () (){
            cout<<" HELLO ADARSH" <<endl;
        }
};
//  3
class DotOverloading{  // this class overloads . operators ---->
    public:
        void operator . (){
            cout<<" HELLO Dotty" <<endl;
        }
};

int main(){
// Ex : 1 

   Overloader obj1, obj2;
   obj1.a = 7;
   obj2.a = 10;

   obj1 + obj2;  // 10 - 7 = 3 will be result

//  Ex : 2
/*
   BraceOverloading obj;
   obj();   // so whenever obj() called it prints HELLO ADARSH
*/

// Ex: 3
/*
    DotOverloading D;
    D.;             // cant do cuz . cant be overloaded
 */
}