// Points......
// 1.Arr.Length() >=3   
// 2. 0 to i        Arr[i]<Arr[i+1]
// 3. i to size     Arr[i]>Arr[i+1]
// 4. return peak index ...Arr[i]<Arr[i+1] < peak >Arr[i]>Arr[i+1] .. greater than both 2 and 3 pts
// the Array looks like a mountain
#include<iostream>
using namespace std;

int MountainArray(int Arr[],int size){
    int start = 0, end = size-1;
    int mid = start + (end - start)/2;

    while(start < end ){
        if(Arr[mid] < Arr[mid+1])
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

    int Arr[] = { 0 , 10 , 50 , 2};     // o/p 2 
    // int Arr[] = { 0 , 2 , 1 , 0 };  // o/p 1 
    int peak = MountainArray(Arr,4);
    cout<< "Peak index  is : "<< peak << endl;
}