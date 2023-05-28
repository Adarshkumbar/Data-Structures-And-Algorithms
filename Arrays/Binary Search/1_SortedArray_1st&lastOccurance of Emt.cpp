//---------Points----------- 
// Array will be sorted we need to find 1st and last occerance of  given emt K
//ex : Arr-[0,0,1,1,2,2,2,2]  K= 2 . O|P : 4 7
//this Follows Binary Search

#include<iostream>
using namespace std;


int firstOccurance(int Arr[],int size,int K){
    int start = 0, end = size-1;
    int mid = (start + (end - start)/2); //  i.e int mid = (start + end )/2; cuz to prevennt size error of 2^31-1 we did this
    int ans=-1;
    while(start<=end){          // stop loop when start > end
        if(K == Arr[mid]){
            ans = mid;
            end = mid - 1;
        }
        else if( K < Arr[mid]){            // go to left part
            end = mid-1;                //this code will get left part of array from mid
        }
        else{                           // go to right part
            start = mid + 1;            //this code will get right part of array from mid
        }
        mid = (start + (end - start)/2);        // i.e (s+e)/2 to prevennt size error of 2^31-1 we did this
    }
    return ans;
}
int lastOccurance(int Arr[],int size,int K){
    int start = 0, end = size-1;
    int mid = (start + (end - start)/2); //  i.e int mid = (start + end )/2; cuz to prevennt size error of 2^31-1 we did this
    int ans=-1;
    while(start<=end){          // stop loop when start > end
        if(K == Arr[mid]){
            ans = mid;
            start = mid + 1;
        }
        else if( K < Arr[mid]){            // go to left part
            end = mid - 1;               //this code will get left part of array from mid
        }
        else{                           // go to right part
            start = mid + 1;            //this code will get right part of array from mid
        }
        mid = (start + (end - start)/2);        // i.e (s+e)/2 to prevennt size error of 2^31-1 we did this
    }
    return ans;
}

int main (){
    int Arr[] = {0,0,1,1,2,2,2,2,3} ;
    int firstOcc = firstOccurance(Arr,9,1) ; // Array , Size and Key 
    cout<<"1st Occurance of 2 is : "<<firstOcc << endl ;

    int lastOcc = lastOccurance(Arr,9,1) ; // Array , Size and Key 
    cout<<"\nlast Occurance of 2 is : "<<lastOcc << endl ;


//************************ Below Code is to Find total number of Occurences of a Key in sorted array*****************************************
    // cout<<"\nTotal Number of Occurences of 2 is : "<<endl;
    // if(firstOcc == -1 && lastOcc == -1 )
    // {
    //     cout<<" 0 "<<endl ;
    // }
    // else{
    //     cout<<( lastOcc-firstOcc)+1 <<endl;
    // }
}