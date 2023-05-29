// Points......
//1.Pivot any number/index of array used to perform operations in ARRAY
//2.Pivot we considered smallest value
//3.Array considered it Sorted and rotated
// ex: [3,8,10,17,1] o/p pivot index is 4
#include<iostream>
using namespace std;

int MountainArray(int Arr[],int size){

    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;

    while(start < end ){
        if(Arr[mid] >= Arr[0])
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
int main (){
    //Array should be sorted and rotated
    // int Arr[] = { 0 , 10 , 50 , 2};     // o/p 3 
    int Arr[] = { 0,2,4,5,4,3,1 };  // o/p 6 (Arr,7)
    int peak = MountainArray(Arr,7);
    cout<< "Peak index  is : "<< peak << endl;
}