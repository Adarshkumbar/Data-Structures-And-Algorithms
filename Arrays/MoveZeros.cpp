// 1. move all 0's of array to end of array
// i/p : { 1, 0, 0, 3, 5, 6, 0}
// o/p : { 1, 3, 5, 6, 0, 0, 0}
// 2.logic used is keep one nonZero variable shows end posi of nonZero emts like ....1,2,3,0,0 here nonZero= 3
// just check for nonZero emt and swap Arr[i] with Arr[nonZero++] 

#include<iostream>
#include<stdlib.h>

using namespace std;

void MoveZeros(int  arr[], int size){
    int nonZero = 0 ; // 0th index ....points to end position of non zero emts 
    // cuz they will be present sucessively after every iteration ex:....1,2,3,0,0 here nonZero= 3
    for(int i = 0 ; i < size ; i++)
    {
        if( arr[i] != 0) // check for non zero emts
            swap( arr[i] , arr[nonZero++] ); // increment nonZero to point to new nonzero emts
    }
    cout<< " nonZero = " << nonZero;
}

void Display(int * Arr, int size) {
    for(int i = 0 ; i < size  ; i++){
        cout<<" "<< Arr[i];
    }
}

int main()
{
    int Arr[]= {0,1,0,3,0,15} ; // O/P  1, 3, 15, 0, 0, 0
    
    cout<<"Array is : \n";
    Display(Arr, 6) ;      // 2nd argument is size

    MoveZeros(Arr, 6) ; // 2nd argument is size

    cout<<"\nMoved Zeros : \n";

    Display(Arr, 6) ;      // 2nd argument is size

    return 0 ;
}