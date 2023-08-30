//          a ^ b
//     1. b is even -> a^ (b/2)* a^ (b/2)
//     2. b is odd  -> a * a^ (b/2) * a^ (b/2)

#include<iostream>
using namespace std;

int Power( int a, int b) { 
    // Base Cases
    if( b == 0 )
        return 1;  // ex: 3^0 = 1
    if( b == 1)
        return a;  // ex: 29 ^ 1 = 29
    
    // Recursive call
    int ans = Power ( a , b/2);

    if(b % 2 == 0)  // b is even
        return ans * ans;
    else            // b is odd
        return a * ans * ans;
} 

int main(){
    int a , b;
    cout<<"Enter a and b :";
    cin>>a>>b;
    
    cout<<a<<" ^ "<<b <<" = "<<Power(a , b);


}