#include<iostream>
using namespace std;

class Hero{

    // private members .... using getter and setter for manipulation
        char level ;     // like A B C 
        int health ;
        
    public :
    static int WinStreak;  // static var
    // Default Constructor
        Hero(){
            cout<<"THIS IS CONSTRUCTOR"<<endl;
        }
    //Paramaterised Constructor
        Hero(int x ){
            cout<<"THIS IS PARAMATERISED CONSTRUCTOR : "<< x <<endl;
        }
    // Using this keyword
        Hero( int health , int level){
            this->health = health;    // arrow operator
            (*this).level = level;   // dot operator
        }
    //  Getters
        int getHealth(){
            return health;
        }
        char getLevel(){
            return level;
        }
    // Setters
        void setHealth(int heal){
            health = heal;
        }
        void setLevel( char lvl){
            level = lvl;
        }
        void Print(){
            cout<<"Health :"<<this->health<<endl;
            cout<<"Level :"<<this->level<<endl;
        }
    //  COPY CONSTRUCTOR 
    //  for Static Allocation
        Hero(Hero & temp){
            this->health = temp.health;
            this->level = temp.level;
        }
    // For Dynamic allocation
         Hero(Hero * temp){
            this->health = temp->health;
            this->level = temp->level;
        }

    //  Static Function -- no need an obj to use these and bnelongs to class
    static int random(){
        return WinStreak;
    }
    // DESTRUCTOR ... by default present or we can create one too
    ~Hero(){
        cout<<"THIS IS DESTRUCTOR"<<endl;
    }
};
//  static data member initialisation
int Hero :: WinStreak = 100;
int main(){
    //  Object initialisation
//  STATIC ALLOCATION  --------------------------------------------------------------
//     Hero h1 ; // or Hero h1( value );
//     h1.setHealth(68);
//     cout<<" h1 health :"<<h1.getHealth()<<endl;

//     h1.setLevel('B');
//     cout<<" h1 Level :"<<h1.getLevel()<<endl;

// // DYNAMIC ALLOCATION    --------------------------------------------------------------
//     Hero * h2 = new Hero;   // just like ..... int *ptr = new int;
    
//     // 1. Using . (dot) operator  FOR DYNAMIC ALLOCATION
//     (*h2).setLevel('A');
//     cout<<" h2 Level :"<<(*h2).getLevel()<<endl;
//     // 2. Using . (dot) operator  FOR DYNAMIC ALLOCATION
//     h2->setHealth(95);
//     cout<<" h2 health :"<<h2->getHealth()<<endl;

// //   -------------------------------------------------------------- --------------------------------------------------------------
//     // this keyword ... represents current object
//     Hero h3( 99, 'S');
//     cout<<" h3 level :"<<h3.getLevel()<<endl<<" h3 Health :"<<h3.getHealth() <<endl;

//   -------------------------------------------------------------- --------------------------------------------------------------
//  COPY CONSTRUCTOR 
    //  there will be default copy constructor defined by compiler .....
    //  IF we Define our COPY Constructor default will be removed
// STATIC ALLOCATION    
    Hero Hulk(89,'A'); 
    Hero WW(Hulk);
    WW.Print();

// DYNAMIC ALLOCATION
    Hero *IronMan = new Hero(100,'S');  
    Hero SpiderMan(IronMan);  // passing obj as an ARGUMENT
    IronMan->Print();
    SpiderMan.Print();

// ------------------------------------------------------------------------------------------------------
// STATIC VARIABLE and STATIC FUNCTION
    cout<< Hero :: random()<<endl;
    cout<< Hero :: WinStreak;
    Hero :: WinStreak = 111;
    cout<< Hero :: random()<<endl;
    cout<< Hero :: WinStreak;
}