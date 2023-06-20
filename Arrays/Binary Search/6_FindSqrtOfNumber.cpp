// Points to Note 
// 1. cant use Built in exponential ** funtion 
// 2. Using Binary search cuz timecomplexity should be log(n)

#include <iostream>
using namespace std;

int BinarySearch(int num) {
    int s = 0 ;
    int e = num;
    int mid = s + (e-s)/2;
    int ans = -1;
    while (s <= e){
        if((mid * mid) == num){
            return mid ;
           
        }
        if((mid * mid ) < num )
        {
              s = mid + 1;
              ans = mid ;
        }
        else{
            e = mid - 1 ;
        }
         mid = s + (e-s)/2;
    }
    return ans ;
}

double morePrecision (int n , int prec , int intPart)
{ // prec is precision .... how many no.s after decimal  
    double frac = 1;
    double  ans = intPart;
    for (double i = 0 ; i < prec ; i++ )
    {
            frac = frac/10 ;// to get .1 .01 .001 so on
            for(double j = ans ; (j*j) < n ; j = j + frac ){
                ans = j ;
            }
    }
    return ans ;
}

int main (){
    int n;
    cout<< " Enter a Number to find Sqrt : "<< endl ;
    cin >> n ;
    
    int intPart = BinarySearch(n) ;  // this only returns int part 
    double ans = morePrecision(n,3,intPart);  // this  will retrun intpart+decimal part 

    cout<< " ans is "<< ans ;
}