/*
Given an integer array coins[ ] of size N representing different denominations of currency and an integer sum, find the number of ways you can make sum by using different combinations from coins[ ].  
Note: Assume that you have an infinite supply of each type of coin. And you can use any coin as many times as you want.

Example 1:

Input:
N = 3, sum = 4
coins = {1,2,3}
Output: 4
Explanation: Four Possible ways are: {1,1,1,1},{1,1,2},{2,2},{1,3}.
Example 2:

Input:
N = 4, Sum = 10
coins = {2,5,3,6}
Output: 5
Explanation: Five Possible ways are: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        vector<vector<long long int >> dp(N+1 , vector<long long int> (sum + 1, 0));
        
        for( int i = N ; i >= 0 ; i--){
            for(int j = sum ; j >=0 ; j--){
                if( j == sum) dp[i][j] = 1;
                else if ( i == N) dp[i][j] = 0;
                else{
                    if( j + coins[i] > sum){
                        dp[i][j] = (i + 1 <= N) ? dp[ i +1 ][j] : 0;
                    }
                    else{
                        dp[i][j] = dp[i][j + coins[i]] + (( i+1 <= N) ? dp[i+1][j] : 0);
                    }
                }
            }
        }
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends