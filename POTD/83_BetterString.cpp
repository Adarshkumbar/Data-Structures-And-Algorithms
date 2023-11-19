//                      Better String
//  HARD
/*
GfG Weekly + You = Perfect Sunday Evenings!
Register for free now

banner
Given a pair of strings of equal lengths, Geek wants to find the better string. The better string is the string having more number of distinct subsequences.
If both the strings have equal count of distinct subsequence then return str1.

Example 1:

Input:
str1 = "gfg", str2 = "ggg"
Output: "gfg"
Explanation: "gfg" have 6 distinct subsequences whereas "ggg" have 3 distinct subsequences. 

Example 2:

Input: str1 = "a", str2 = "b"
Output: "a"
Explanation: Both the strings have only 1 distinct subsequence. 
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countSub(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            
            char ch=s[i-1];
            
            if (mp.find(ch) != mp.end()) {
                dp[i] = dp[i] - dp[mp[ch]];
            }

            mp[ch] = (i - 1);
        }

        return dp[n];
    }
    
    string betterString(string str1, string str2) {
        int x = countSub(str1);
        int y = countSub(str2);

        if (x < y) {
            return str2;
        }

        return str1;
    }
};

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    Solution obj;
    string ans = obj.betterString(str1, str2);
    cout << ans << "\n";
}
