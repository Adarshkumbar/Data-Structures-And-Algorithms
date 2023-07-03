// Number of 1 Bits
// Given a positive integer N, print count of set bits in it. 

/*Input:
        N = 6
        Output:2
        
        Explanation:
            Binary representation is '110' 
            So the count of the set bit is 2.
*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        int count = 0 ; // count number of 1's
        int x = N;
        while( x >= 2){
            if( x % 2 == 1)
                count++;
            x = x /2;
        }
        if( x == 1)
            count++ ;
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends