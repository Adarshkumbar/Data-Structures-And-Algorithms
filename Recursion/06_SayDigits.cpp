//              Say Digits
//  I/P : 123 -> O/P : one two three
//  I/P : 444 -> O/P : four four four

#include<iostream>
using namespace std;


void sayDigits( int n ,string arr[]){

    // 1. Base Case
    if( n == 0)
        return ;

    // 2. Processing
    // getting digits out
    int digit = n % 10;
    // remove digit from number / reduce it 
    n = n/10;

    //3.  Recursive call
    sayDigits(n, arr);
    cout<<arr[digit]<<" ";
}

int main (){
    int n ; // number
    // creating string array to store zero to nine as 0 to 9
    string arr[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

    cout<<"Enter the Number :";
    cin>> n;

    sayDigits(n,arr);
}