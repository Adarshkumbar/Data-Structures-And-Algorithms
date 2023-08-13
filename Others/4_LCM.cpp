#include<iostream>
using namespace std;

//   LCM * GCD = A*B
int GCD( int a, int b){
    if( a == 0 )
        return b;
    if( b == 0 )
        return a;
    while( a!=b ){
        if( a > b)
            a = a - b ;
        else    
            b = b - a ;
    }
    return a;
}

int LCM ( int a , int b){
    int gcd = GCD(a,b);

    return (a*b)/gcd;
}

int main(){
    int a, b ;
    cout<<"Enter values of a and b :";
    cin>>a>>b;

    cout<<"GCD of "<<a<<" and "<<b<<" is :"<<LCM(a,b)<<endl;

}