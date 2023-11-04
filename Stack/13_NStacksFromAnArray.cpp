//              N StacksFrom an Array
//  Hard

#include<iostream>
using namespace std;


class NStack{
    private:
        int * arr;
        int * next;
        int * top;

        int n , s ;  // n for no. of stacks and s for size of arr
        int freeSpace;

    public:
        NStack( int n , int s){
            this -> n = n;
            this -> s = s;
            arr = new int[s];
            next = new int[s];
            top = new int [n];
        
        //  top initialising 
            for( int i = 0 ; i < n ; i++){
                top[i] = -1;
            }
        //  next initialising 
            for( int i = 0 ; i < n ; i++){
                next[i] = i + 1;
            }
            next[s-1] = -1;  // last index to -1 cuz no space ahead

        //  update freeSpace
            freeSpace = 0;
        }

// -------------- PUSH X into mth stack
        bool push1(int X, int m ) 
        {
            if( freeSpace == -1)  // Stack overflow
                return -1 ; 
            //  step 1 - Get index;
            int index = freeSpace;

            //  step - 2 update free space 
            freeSpace = next[index];

            //  Step - 3 push emt;
            arr[index] = X;

            //  Step - 4 update next ;
            next[ index ] = top[ m -1];

            //  Step - 5 update top;
            top[m-1] = index;

            return true;
        }
        bool pop1(int m )
        {
            //  Stack UnderfLow
            if( top[m-1] == 0)
                return -1;
            //  Step - 1
            int index = top[m-1];

            //  Step -2 ;
            next[ m -1] = index ;

            //  Step - 3
            next[index] = freeSpace ;

            //  Step - 4
            freeSpace =  index ;
        }
};

int main(){
   NStack stk(3,8);
   stk.push1(10,1);

}