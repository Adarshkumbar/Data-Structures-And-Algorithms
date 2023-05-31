#include<iostream>
using namespace std;

int getPivot(int arr[],int size){

    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;

    while(start < end ){
        if(arr[mid] >= arr[0])
        {
            start = mid + 1;// getting closer to peak from left
        }
        else{
            end = mid ; // getting closer to peak from right
        }
        mid = start + (end - start)/2;
    }
    return start  ;
}

int BinarySearch(int arr[] ,int s,int e ,int key ){
    int start = s, end = e; 
    int mid = (start + end)/2;   

    while(start<=end){ 
    
        if(arr[mid] == key ){
            return mid ;
        }

        else if( key > arr[mid] ) {        
            start = mid + 1 ;   
        }

        else{       
            end = mid - 1 ;   
        }
        mid = (start + end )/2; 
    }
    return -1;
}
int main (){
    int k=2;
    int arr[]={5,6,7,1,2,3};
    int pivot = getPivot(arr,6);
    if(k >=arr[pivot] && k <=arr[6-1])  //[size-1] 
    { //search on 2nd line i.e Greater part of array
        return BinarySearch(arr,pivot,6-1,k);
    }
    else{//search on 1st line i.e Smallest part of array
        return BinarySearch(arr,0,pivot-1,k);
    }
}