//              Types Of Inheritance
//  1. Single Inheritance A ---> B
//  2. Multiple Inheritance A ---> C && B --> C
//  3. Multi Level Inheritance A --> B --> C
//  4. Hierarchial Inheritance  A -->B ... A -->C
//  5. Hybrid Combination of any other 2 Types

// 1) Already Discussed in 3_Inheritance.cpp


#include<iostream>
using namespace std;

// 2 ) MultiLevel Inheritance
// --------------------------------------------------------------------------------------------------------------
/*
class Animal {
    private :
        bool Veribrate  = true ; // this cant be accessed by any derived class
    public :
        int height ;
        int weight ; 
        int age;
    // Animal(){                    // constructor
    //     cout<<"This Is Animal"<<endl;
    // }
        void Sound(){
            cout<<" Animal Makes Sound"<<endl;
        }
};
class Dog : public Animal{
    public:
    // Dog(){
    //     cout<<"This Is Dog"<<endl;
    // }
        void Bark(){
             cout<<" Bow Bow"<<endl;
        }
};
class BullDog : public Dog{
    public:
    // BullDog(){
    //     cout<<"This Is BullDog"<<endl;
    // }
        void Barks(){
            cout<<" Voof Voof"<<endl;
        }
};  */
// --------------------------------------------------------------------------------------------------------------

//  3) Multiple Inheritance
/*
class Cpu{
        int ram = 16;
        int rom = 1000;
    public:
        void Specs(){
            cout<<"ram : "<<ram <<"gb rom :"<<rom<<"gb"<< endl;
        }
};

class Monitor{
        int RefreshRate = 144;
    public:
        void Display(){
            cout<<" ASUS MONITOR"<<endl;
        }
};

class Computer : public Cpu , public Monitor{
    public:
        void myPc(){
            cout<<"THIS IS COMPUTER"<<endl;
        }
};
*/      
// --------------------------------------------------------------------------------------------------------------
//  4) Hierarchical Inheritance
/*
class Human{            // Parent
    int age ;
    int height ;
    int weight;

    public:
        void getAge(){
            cout<<"Age : "<<age<<endl;
        }
        void Print(){
            cout<<"height :" << height << " Weight :" << weight<<endl;
        }
};
class Male: public Human{
    public :
        void Print(){
            cout<<" This is Male "<<endl;
        }
};

class Female : public Human{
    public :
        void Print(){
            cout<<" This if Female";
        }
};
*/
// --------------------------------------------------------------------------------------------------------------
// 5) Hybrid Inheritance          
//  ex :                ____A____
//                      |       |
//                      B_______C   
//                          |
//                          D

class A{
    int x = 1;
    public:
        A(){
            cout<<"This is A Constructor "<<endl;
        }
        void Printx(){
            cout<<"X is "<<x;
        }
        void Show(){
            cout<<" SHOW "<<endl;
        }
        ~A(){
             cout<<"This is A Destructor  "<<endl;
        }
};
class B: public A{
        int b = 2; 
        public:
            B(){
                cout<<"This is B Constructor "<<endl;
            }
            void Printb(){
                cout<<" B is "<<b<<endl;
            }
             ~B(){
             cout<<"This is B Destructor  "<<endl;
        }
};
class C : public A{
        int c = 3;
        public:
            C(){
                cout<<"This is C Constructor "<<endl;
            }
            void Printc(){
                cout<<" C is "<<c<<endl;
            }
             ~C(){
             cout<<"This is C Destructor  "<<endl;
        }
};

class D : public B, public C{
        int d = 4;
        public:
            D(){
                cout<<"This is D Constructor "<<endl;
            }
            void Printd(){
                cout<<" D is "<<d<<endl;
            }
            ~D(){
             cout<<"This is D Destructor "<<endl;
        }
};
// --------------------------------------------------------------------------------------------------------------

int main(){
// --------------------------------------------------------------------------------------------------------------
// 2 ) MultiLevel Inheritance
/*   
    BullDog B;
    B.Bark();
    B.Barks();
    B.Sound();
*/ 
// --------------------------------------------------------------------------------------------------------------
//  3) Multiple Inheritance
/*
    Computer C;
    C.Display();
    C.Specs();
    C.myPc();
*/
// --------------------------------------------------------------------------------------------------------------
//  4) Hierarchical Inheritance
/*
    Male M;
    M.Print();

    Female F;
    F.Print();
    F.getAge();
 */
// --------------------------------------------------------------------------------------------------------------
// 5) Hybrid Inheritance     
    D obj;
    obj.Printd();
    obj.Printb();
    obj.Printc();
}