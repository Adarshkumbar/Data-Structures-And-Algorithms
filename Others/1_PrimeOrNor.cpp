#include<iostream>
using namespace std;

// funtion returns true if PRIME
bool isPrime( int N ){
    if( N<=1)
        return false;       // cuz 1 is not PRIME
    for( int i = 2 ; i < N ; i++){  // logic is if number divided by any other no rather than 1 and N itself is not prime
            if( N % i == 0)
                return false;
    }
    return true;
}
int main(){
    int N;
    cout<<"Enter a NUMBER :";
    cin>>N;
    if( isPrime(N))
        cout<<N<<" is PRIME";
    else    
        cout<<N<<" is not PRIME";
}