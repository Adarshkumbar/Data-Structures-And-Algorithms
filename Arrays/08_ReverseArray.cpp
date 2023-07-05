// JUST go on swapping  s and e man 

#include<iostream>
#include<stdlib.h>

using namespace std;

void ReverseArray(int * arr, int size){
    int s = 0 ;
    int e = size - 1 ;
    while( s <= e ){
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}

void Display(int * Arr, int size) {
    for(int i = 0 ; i < size  ; i++){
        cout<<" "<< Arr[i];
    }
}

int main()
{
    int Arr[]= {1,2,3,4,5,6} ;
    
    cout<<"Array is : \n";
    Display(Arr, 6) ;      // 2nd argument is size

    ReverseArray(Arr, 6) ; // 2nd argument is size

    cout<<"\nReversed Array is : \n";

    Display(Arr, 6) ;      // 2nd argument is size

    return 0 ;
}