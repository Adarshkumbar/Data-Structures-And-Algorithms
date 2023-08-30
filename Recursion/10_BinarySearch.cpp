//          Binary Search Using Recursion

#include<iostream>
using namespace std;

bool BinarySearch(int arr[] , int s , int e , int key){
        
        if(s > e)
             return false;
        int mid = s + ( e - s ) / 2 ;
//              base case 2
        if( arr[mid] == key)
            return true; 
        
//      Recursive call
        if( arr[mid] < key)    // right part
            BinarySearch( arr , mid+1 , e , key);
        else                   // left part
            BinarySearch( arr , s , mid-1 , key);
}

int main(){
    int arr[5] = { 1 ,2 , 3 , 4 , 5 };
    int size = 5;
    int key = 51;
    BinarySearch( arr , 0 , size-1, key) ? cout<<" Found " : cout<<" Not Found ";
}