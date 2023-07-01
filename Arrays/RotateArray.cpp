// 1. we need to rotate array k steps.
// 2. Basically we are moving every emt of array so we store in " temp "
// 3. Ex: { 1, 2, 3, 4 } k = 2 O/P : { 3, 4 , 1 , 2}
// 4. using mod operator (%) cuz we want to get back to initial state like circular queue

#include<iostream>
#include<stdlib.h>

using namespace std;
void Display(int *, int);

void RotateArray(int * arr, int size, int k){  // k shows how much to rotate
    int temp [size] ={0} ; // creating temp to store rotated items basically rotated array in the end

    for( int i = 0 ; i < size ; i++)
    {
        temp[( k + i) % size] = arr[i] ; 
    }
     cout<<"\nRotated Array is : \n";

    Display(temp, 6) ;      // 2nd argument is size
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
    Display(Arr, 6 ) ;      // 2nd argument is size

    RotateArray(Arr, 6, 3) ; // 2nd argument is size and  3rd argument is k steps

    return 0 ;
}