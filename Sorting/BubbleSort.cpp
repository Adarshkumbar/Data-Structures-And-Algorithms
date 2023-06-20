// 1. Best  time Complexity O(n) -- ex : Sorted array and Worst time Complexity O(n^2)
// 2. Outer loop i = 1 to n - 1 and Inner loop to compare emts if(arr[j] > arr[j+1]) swap else ignore and continue with next iteration

#include<iostream>
using namespace std;

int BubbleSort(int * arr , int n ){
    int alrSwapped = false ; // this variable used to check whether arr is sorted or not
    for(int i = 1 ; i < n-1 ; i++) // outer loop to traverse 
    {
        for( int j = 0 ; j < n-i ; j++)
            if(arr[j] > arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
                alrSwapped = true;
            }
            if( alrSwapped == false)  // no swap cuz  alr sorted right? that's why we exit loop
                break; 
    }
}

int main()
{
    int Array[] = { 22 , 11, 22, 33, 5, 6 , 19};
    int n = 7; // size of above array 
    
    BubbleSort(Array , n);
    
    for (int i = 0; i < n; i++)
    {
       cout << ' '<< Array[i] << ' ' ;
    }
    
}