// 1.Best and Worst time Complexity O(n^2)
// 2.Loop From index i = 0 to n-1 ....run another loop j from i+1 to n to find minIndex from array

#include<iostream>
using namespace std;

int selectionSort(int * arr , int n ){
    int i , j , minIndex ;
    for(int i = 0 ; i < n-1 ; i++)  // traverse the array
    {
         minIndex = i ; // this index  will have minValue from array
        for(  j = i+1 ; j<n ; j++) // traverse the array 
        {
            if(arr[j]<arr[minIndex]) // check for min value in array
                minIndex = j ;
        }
        swap(arr[i], arr[minIndex]); // swap with minIndex value 
    }
}

int main()
{
    int arr[] = {12,33,1,4,77};
    int n = 5;
    selectionSort( arr, n );
    cout<<"Array sorted using Selection Sort : \n";
    for( int i = 0 ; i < 5 ; i++)
    {
        cout << ' '<< arr[i]<< ' ';
    }
} 
