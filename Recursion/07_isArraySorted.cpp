            //  IS Arrays Sorted ?
//  I/P : 1 2 34 55 -> O/P : Sorted
//  I/P : 4 2 -> O/P : Not sorted

#include<iostream>
using namespace std;


bool isSorted( int *arr , int size){
        //    Base case
        if( size == 0 || size == 1 )  // which means 1 emt or 0 emt in arry which is sorted
            return true;
        // processing and recursive relation
        if( arr[0] > arr[1] )  // means not sorted
            return false ;
        else{
            bool remainingPart = isSorted( arr+1 , size-1); // since one comparison done do next part and reduce size
            return remainingPart;
        }
}

int main (){
    int arr[5] ;
    cout<<"Enter 5 numbers : ";
    
    for(int i = 0 ; i < 5 ; i++){
        cin>>arr[i];
    }
    // int arr[5] = {11 ,2 , 4 , 5, 19};
    isSorted(arr, 5) ? cout<<"Array is Sorted "<<endl : cout<<"Array is not Sorted "<<endl ;
}