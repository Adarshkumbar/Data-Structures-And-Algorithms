/*
The key process in quickSort is a partition(). The target of partitions is to place the pivot (any element can be chosen to be a pivot) at its correct position in the sorted array and put all smaller elements to the left of the pivot, and all greater elements to the right of the pivot.

Partition is done recursively on each side of the pivot after the pivot is placed in its correct position and this finally sorts the array.
*/ 


#include<iostream>
using namespace std;

int partition(int arr[] , int s , int e ){
    int pivot = arr[s];
    
    // count no of emts less than pivot
    int cnt = 0 ;

    for( int i = s + 1 ; i<=e ; i++){
        if( arr[i] <= pivot)
        {
            cnt++;
        }
    }
    // okace pivot at right position
    int pivotIndex = s + cnt ;
    swap(arr[pivotIndex], arr[s]);

    // left and right part taking care of 
    int i = s , j = e ;

    while( i < pivotIndex && j > pivotIndex){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if( i < pivotIndex && j > pivotIndex){
            swap(arr[i++] , arr[j--]);
        }
    }
    return pivotIndex;
}

void QuickSort( int arr[] , int s , int e ){
    //  BASE CASE
    if( s >= e)
        return ;
    
    // Partition
    int p = partition( arr, s, e);

    // left part Sort
    QuickSort( arr , s , p-1);

    // left part Sort
    QuickSort( arr , p+1, e);
}


int main(){
    int arr[8] = { 11, 2, 33, 1, 9 , 0 , 12, 4};
    int size = sizeof(arr)/4 ;
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    QuickSort(arr, 0,size);                            //^
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  
    cout<<"\nAfter sorting :"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}