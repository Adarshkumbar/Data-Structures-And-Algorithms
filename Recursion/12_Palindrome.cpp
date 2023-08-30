#include<iostream>
using namespace std;

bool Reverse( string str , int i , int j) { // i and j are starting and end pointers 
//          BASE CASE
    if( i > j)
        return true;
    
//          Processing
    if( str[i] != str[j])
        return false;
    
    // Recursive call
    Reverse(str , ++i , --j);
} 

int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    
    Reverse( str , 0 , str.length() - 1 ) ? cout<<"\nIts Palindrome " :  cout<<"\nIts Not a Palindrome ";


}