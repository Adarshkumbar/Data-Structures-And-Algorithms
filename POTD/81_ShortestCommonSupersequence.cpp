//                      Shortest Common Supersequence
//       medium -> using dp
/*
Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
Note: X and Y can have both uppercase and lowercase letters.

Example 1

Input:
X = abcd, Y = xycd
Output: 6
Explanation: Shortest Common Supersequence
would be abxycd which is of length 6 and
has both the strings as its subsequences.
Example 2

Input:
X = efgh, Y = jghi
Output: 6
Explanation: Shortest Common Supersequence
would be ejfghi which is of length 6 and
has both the strings as its subsequences.
*/
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
         int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return (m+n-dp[m][n]);
    }
};

//{ Driver Code Starts.

int main()
{   
 
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
	return 0;
}
