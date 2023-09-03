#include<iostream>
using namespace std;

void InsertionSort( int arr[] , int pivot,int size){
    if( size == 0 || size == 1)
        return ;
    if( arr[pivot] > arr[0])
        
    
}

int main(){
    int arr[8] = { 11, 2, 33, 1, 9 , 0 , 12, 4};
    int size = sizeof(arr)/4 ;

    InsertionSort(arr, 1,size);
    cout<<"\nAfter sorting :"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}