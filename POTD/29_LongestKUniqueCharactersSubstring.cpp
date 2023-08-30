//                  Longest K unique characters substring
// diff: Medium
/*
Given a string you need to print the size of the longest possible substring that has exactly K unique characters. If there is no possible substring then print -1.

Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 
7
Explanation: 
"cbebebe" is the longest substring with 3 distinct characters.
Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: 
There's no substring with 2 distinct characters.
*/

//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int l, r;
        int n = s.size();
        
        l = r = 0;
        
        int ans = -1;
        map<char,int> f;
        
        while(r < n){
            ++f[s[r]];
            
            while(f.size() > k){
                --f[s[l]];
                if(f[s[l]] == 0)
                    f.erase(s[l]);
                    
                ++l;
            }
             
            if(f.size() == k)
                ans = max(ans, r - l + 1);
                
            ++r;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends