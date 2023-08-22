#include<iostream>
using namespace std;

void Counting ( int n ){
    if( n == 0) // base case
        return ;
    cout<< n << " " ;  // processing
    Counting(n-1);  // recursive relation
}

int main(){
    int n ;
    cout<<"Enter n :";
    cin>>n;

    Counting(n);
    return 0;
}