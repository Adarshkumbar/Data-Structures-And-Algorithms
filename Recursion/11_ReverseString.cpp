#include<iostream>
using namespace std;

void Reverse( string & str , int i , int j) { // i and j are starting and end pointers 
//      Base case
    if( i > j)
        return;
//      Processing
    swap(str[i], str[j]);
        i++;
        j--;
//      Recursive call
    Reverse( str , i , j);   // or  Reverse( str , ++i , --j);
} 

int main(){
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    
    cout<<"\nString is : " <<str;
    Reverse( str , 0, str.length() - 1);
    cout<<"\nAfter Reverse : " <<str;

}