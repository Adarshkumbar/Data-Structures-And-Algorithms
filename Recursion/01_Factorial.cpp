#include<iostream>
using namespace std;

int fact ( int n ){
    // Base case
    if( n <= 0)
        return 1;
    return n* fact(n-1);
}

int main(){
    int n ;
    cout<<"Enter n :";
    cin>>n;

    cout<<n<<"! = "<<fact(n);
    return 0;
}