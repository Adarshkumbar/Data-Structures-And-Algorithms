#include<iostream>
using namespace std;

void BubbleSort( int arr[] , int size){
    // Base case 
    if( size == 0 || size == 1)
        return;
    //  Processing
    //  need to put largest emt at end
    for( int i = 0 ; i < size-1; i++){
        if( arr[i] > arr[i+1])
            swap(arr[i] , arr[i+1]);
    }
    BubbleSort(arr, size-1);
}

int main(){
    int arr[8] = { 11, 2, 33, 1, 9 , 0 , 12, 4};
    int size = sizeof(arr)/4 ;

    BubbleSort(arr, size);
    cout<<"\nAfter sorting :"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}