#include<iostream>
using namespace std;

int StairWays ( int n ){
    // base case
    if( n < 0)  // means no stair present so 0 
        return 0;

    if( n == 0)  // means to reach same stair 1 way
        return 1;

 // recursive relation

//  to reach a stair either 1 step or 2 steps so
    int ans =  StairWays(n-1) + StairWays(n-2);
}
   

int main(){
    int n ;
    cout<<"Enter nth Stair :";
    cin>>n;

    cout<<"\nNo of WAys to reach "<<n<<"th Star is "<<StairWays(n);
    return 0;
}