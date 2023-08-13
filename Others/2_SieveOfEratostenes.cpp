//            SieveOfEratostenes

#include<iostream>
#include<vector>
using namespace std;

int cntPrime( int n ){
    int count = 0 ;  // count no. of Prime number

    vector<bool>prime(n+1 , true);  // stores n+1 numbers with true i.e ALL NUMBERS AS PRIME
    //  logic is to cut of non prime numbers ... from 2.  written in book

    prime[0] = prime[1] = true; // 
    for( int i = 2 ; i < n ; i++){
        if( prime[i])
            count++;
        for(int j = 2*i ; j < n ; j = i + j){
            prime[j] = false;
        }
    }
    return count;
}

int main(){
    int n ;
    cout<<"Enter number :";
    cin>>n;
    int count = cntPrime(n);
    cout<<"No of prime number is :"<<count;
}