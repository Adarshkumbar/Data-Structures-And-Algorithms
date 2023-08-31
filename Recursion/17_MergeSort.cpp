#include<iostream>
using namespace std;

void merge( int arr[] , int s , int e){
     int mid = (s+e)/2;

    //   1st array and 2nd array lengths
    int len1 = mid - s + 1;
    int len2 = e - mid;

    //  creating 2 arrays dynamically
    int *first = new int[len1];
    int *second = new int[len2];

    //  copy values for 1st array
//  k is main array index which was initially given to us
    int k = s;
    for( int i = 0 ; i < len1 ; i++){
        first[i] = arr[k++];
    }
  //  copy values for 2nd array
    k = mid+1;
    for( int i = 0 ; i < len2; i++){
        second[i] = arr[k++];
    }

//      merge the arrays like MERGE 2 SORTED ARRAYS
    int index1 = 0 ;
    int index2 = 0 ;
    k = s;

    while( index1 < len1 && index2 < len2){
        if( first[index1] < second[index2])
            arr[k++] = first[index1++];
        else    
            arr[k++] = second[index2++];
    }
    //  when len of one array is greater than other
    while( index1 < len1)
        arr[k++] = first[index1++];
    while( index2 < len2)
        arr[k++] = second[index2++];
}

void MergeSort( int arr[], int s ,int e){
    if( s>= e )
        return ;

    int mid = s + (e - s) /2;
    // sort left part
    MergeSort(arr, s , mid);
    
    // sort right part 
    MergeSort(arr , mid+1 , e);
    
//  NOW merge
    merge(arr, s , e);
    
}

int main(){
    int arr[8] = { 11, 2, 33, 1, 9 , 0 , 12, 4};
    int size = sizeof(arr)/4 ;
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    MergeSort(arr, 0,size);                            //^
//  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  
    cout<<"\nAfter sorting :"<<endl;
    for(int i = 0 ; i < size ; i++){
        cout<<arr[i]<<" ";
    }
}