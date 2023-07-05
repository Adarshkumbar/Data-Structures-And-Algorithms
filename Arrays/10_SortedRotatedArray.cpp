// 1. we need to check for sorted rotate array 
// 2. Point: there can be only 0 or 1 pair such that Arr[i-1] > Arr[i]  cuz sorted
// 3. Ex:{ 3, 4 , 1 , 2}  O/P : True cuz only 1 pair with Arr[i-1] > Arr[i] also rotating gives ....{1,2,3,4}

#include<iostream>
#include<stdlib.h>

using namespace std;
void Display(int *, int);

bool CheckSortedRotateArray(int * arr, int size){ 
    // we are gonna check atmost 1 pair with A[i-1] > A[i] if present true
    // else false...more than 1 pair
    int count = 0 ;// so to keep count we  of pair we use this
    for (int i = 1; i < size; i++)
    {
       if(arr[i-1] > arr[i])
            count++;
    }
    // we will be left with last emt ,,,we compare with 1st emt
    if(arr[size-1] > arr[0])  // last and first
            count++;

    return count <=1; // if count 0 or 1 true else false
    
}

void Display(int * Arr, int size) {
    for(int i = 0 ; i < size  ; i++){
        cout<<" "<< Arr[i];
    }
}

int main()
{
    int Arr[]= {4,5,6,1,2,3} ;          // op true
    
    // int Arr[]= {1,2,3,11,4,5,6} ;    // op false

    // int Arr[]= {1,2,3,4,5,6} ;       // op true
    cout<<"Array is : \n";
    Display(Arr, 6 ) ;                  // 2nd argument is size

    bool x = CheckSortedRotateArray(Arr, 6) ; // 2nd argument is size 
     
    cout<< "\n" << x ;
    return 0 ;
}