            // Arrays SUM
//  I/P : 1 2 3-> O/P : 6
//  I/P : 4 2 1 -> O/P : 7

#include<iostream>
using namespace std;


bool linearSearch( int *arr , int size , int k){
    //     Base Case
    if( size == 0)   // means end of arr reached and yet key not found
        return false;
    //  processing 
    if( arr[0] == k)
        return true;
    // Recursive call
    return linearSearch( arr+1 , size - 1 , k);
}

int main (){
    int arr[5] , key ;
    cout<<"Enter 5 numbers : ";
    
    for(int i = 0 ; i < 5 ; i++){
        cin>>arr[i];
    }
    cout<<"Enter key :" <<endl;
    cin>> key;
     linearSearch(arr, 5, key) ? cout<<"Key is Found "<<endl : cout<<"Key not Found"<<endl ;
}