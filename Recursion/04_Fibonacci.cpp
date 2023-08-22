
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    int nthFibonacci(int n){
        int  mod = 1e9 + 7;
        
        //  Base condition
        if( n == 0)
            return 0;
        if( n == 1)
            return 1;
        int ans = ( nthFibonacci(n - 1) % mod + nthFibonacci(n - 2) % mod ) % mod;
        return ans;
    }
};

int main() {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    return 0;
}
