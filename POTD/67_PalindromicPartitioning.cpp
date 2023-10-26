//                      Palindromic Partitioning
//  hard
/*
Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. Determine the fewest cuts needed for palindrome partitioning of the given string.


Example 1:

Input: str = "ababbbabbababa"
Output: 3
Explaination: After 3 partitioning substrings 
are "a", "babbbab", "b", "ababa".
Example 2:

Input: str = "aaabba"
Output: 1
Explaination: The substrings after 1
partitioning are "aa" and "abba".
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
   bool isPalindrome(int i, int j, string& str) {
        while(i<j) {
            if(str[i]!=str[j]) 
                return false;
            i++,j--;
        }
        return true;
    }
    int solve(int i,int n,string &str,vector<int>&dp) {
        if(i==n) {
            return 0;
        }
        int mini = INT_MAX;
        if(dp[i]!=-1)
            return dp[i];
        
        for(int j = i; j<n; j++) {
            if(isPalindrome(i,j,str)) {
                int cost = 1 + solve(j+1, n, str,dp);
                mini = min(mini,cost);
            }
               }
        return dp[i]=mini;
    }
    int palindromicPartition(string str)
    {
        int n = str.size();
        vector<int>dp(n,-1);
        return solve(0,n,str,dp)-1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}