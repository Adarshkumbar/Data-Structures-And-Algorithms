            // Arrays SUM
//  I/P : 1 2 3-> O/P : 6
//  I/P : 4 2 1 -> O/P : 7

#include<iostream>
using namespace std;


int arrSum( int *arr , int size){
    //     Base Case
    if( size == 0)
        return 0;
    if( size == 1)
        return arr[0];
    
    int remainingPart = arrSum ( arr+ 1 , size - 1);   // gets remaining part 
    int sum = arr[0] + remainingPart ; 
    return sum;
}

int main (){
    int arr[5] ;
    cout<<"Enter 5 numbers : ";
    
    for(int i = 0 ; i < 5 ; i++){
        cin>>arr[i];
    }
    cout<<"Sum of Array is : "<< arrSum( arr , 5) ;
}