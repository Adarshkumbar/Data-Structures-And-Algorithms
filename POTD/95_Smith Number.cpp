//  Smith Number
// medium
/*
Given a number n, the task is to find out whether this number is a Smith number or not. A Smith number is a composite numbe
r whose sum of digits is equal to the sum of digits of its prime factors.

Example 1:

Input:
n = 4
Output:
1
Explanation:
The sum of the digits of 4 is 4, and the sum of the digits of its prime factors is 2 + 2 = 4.

Example 2:

Input:
n = 378
Output:
1
Explanation:
378 = 21*33*71 is a Smith number since 3+7+8 = 2*1+3*3+7*1.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
     int sumdigit(int x){
        int sum=0;
        while(x){
            sum+=x%10;
            x=x/10;
        }
        return sum;
    }
    
    bool isPrime(int n){
        if(n==1) return false;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0) return false;
        }
        return true;
    }
    
    int smithNum(int n) {
        int sum=sumdigit(n);
        int sum2=0;
        if(isPrime(n)) return 0;
        for(int i=2;i<=n;i++){
            if(n%i==0){
                int s=sumdigit(i);
                while( n>0 && n%i==0){
                    sum2+=s;
                    n=n/i;
                }
            }
        }
        if(sum==sum2) return 1;
        return 0;
    }
};

int main() {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    return 0;
}