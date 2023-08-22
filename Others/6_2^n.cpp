#include<iostream>
using namespace std;

int power( int n ){
    //  Base case
    if( n == 0)
        return 1;
    return 2 * power(n-1);
}

int main(){
    int n ;
    cout<<"Enter n :";
    cin>>n;

    cout<<"2^"<<n<<"! = "<<power(n);
    return 0;
}