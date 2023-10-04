//--------------------------------- Encapsulation -----------------------------------------------

// bundling of properties(data members) and behaviour ( function/methods) 
// 1. Helps in Unit testing    2.Code Reusability       3. Info/Data hiding     4. can make class ReadOnly

// ------------------------------   INHERITANCE     --------------------------------------------
//  Syntax :
//          class derived_class : ac
//1. PARENT CLASS
#include<iostream>
using namespace std;

class Animal {
    private :
        bool Veribrate  = true ; // this cant be accessed by any derived class
         int height ;
    public :
       
        int weight ; 
        int age;

        void Sound(){
            cout<<" Animal Makes Sound"<<endl;
            cout<<this->age;
        }
};
// Child Class
class SingleInheritance : protected Animal{
    int single ;
    public:
        void SingleSound(){
             cout<<" Single Sound"<<endl;
             cout<< " aaaaa -----  "<< this->age<< endl;
        }
};

int main(){
    SingleInheritance S ; 
    S.SingleSound();
    // S.Sound();

    // cout<<" H W A :" << S.age<<" " << S.height << " " <<S.weight;

    Animal A;
    A.Sound();
}