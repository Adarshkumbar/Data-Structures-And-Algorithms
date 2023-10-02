//                      Number of distinct subsequences
// medium
// not using recursion just.....dp with loops
/*
Given a string consisting of lower case English alphabets, the task is to find the number of distinct subsequences of the string
Note: Answer can be very large, so, ouput will be answer modulo 109+7.

Example 1:

Input: 
s = "gfg"
Output: 
7
Explanation: 
The seven distinct subsequences are "", "g", "f", "gf", "fg", "gg" and "gfg" .
Example 2:

Input: 
s = "ggg"
Output: 
4
Explanation: 
The four distinct subsequences are "", "g", "gg", "ggg".

*/
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.length();
	    
	    int long mod = 1000000007 ;
	    // creating dp vector to save answers ....2 4 8 16 ....
	    vector<long long > dp( n+ 1 , 0); 
	    
	    dp[0] = 1 ; // cuz " " is also answer
	    // creating map to remove redundant answers
	    unordered_map<char , int > m;
	    
	    for( int i = 1 ; i <= n ; i ++){
	        dp[i] = 2 * dp[i-1];
	        char ch = s[i-1]; // getting each char to check for redundancy
	        
	        if( m.count(ch)){
	            int j = m[ch]; // return count of perticular char
	            dp[i] = (dp[i] - dp[j] + mod) % mod; // removing redundant data
	        }
	        m[ch] = (i - 1 ) % mod;
	    }
	    return int( dp[n] % mod );
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends