// Points to Remember :
// 1.Array Must be Sorted (Monotonic)
// 2.Range of int is 2^31 - 1 (positive side and 2^32 in negative side)
// 3.Time Complexity "O(logN)"

#include<iostream>
using namespace std;

int BinarySearch(int arr[] ,int size ,int key ){
    int start = 0 , end = size-1 ; // starting index and ending index
    int mid = (start + end)/2;     // mid index         // fine for smaller size if but for greater size 

    // consider mid = start + (end - start)/2

    while(start<=end){ // running code till "start <= end " and stop when " start > end "
    
        if(arr[mid] == key ){
            return mid ;
        }

        else if( key > arr[mid] ) {        // go to right part of array
            start = mid + 1 ;   // cuz starting of right part is mid + 1 and end remains same
        }

        else{       // go to left part of array
            end = mid - 1 ;    // cuz ending of left part mid - 1 and start remains same 
        }
        mid = (start + end )/2; //fine fore smaller size if but for greater size A
    // consider mid = start + (end - start)/2

    }
    return -1;
}
int main (){
    int index;
    int oddArray [] = {1,3,5,7,9};
    int evenArray [] = {0,2,4,6,8,10};
    
    index = BinarySearch(oddArray,5,9);
    cout<<"Index of 9 is : "<<index<<endl;

    index = BinarySearch(evenArray,6,0);
    cout<<"Index of 0 is : "<<index<<endl;

}