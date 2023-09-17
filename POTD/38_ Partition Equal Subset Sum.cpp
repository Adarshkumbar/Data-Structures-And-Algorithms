//      Partition Equal Subset Sum
/*
Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

Example 1:

Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.
Example 2:

Input: N = 3
arr = {1, 3, 5}
Output: NO
Explanation: This array can never be 
partitioned into two such parts.
*/ 
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        bool dfs(int ind, int N, int target,int arr[], vector<vector<int>>& dp){
        if(ind>=N){
            if(target==0) return true;
            return false;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool not_pick= dfs(ind+1,N,target,arr,dp);
        bool pick=0;
        if(target>=arr[ind]){
            pick=dfs(ind+1,N,target-arr[ind],arr,dp);
        }
        return dp[ind][target]= pick | not_pick;
    }
    
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        vector<vector<int>> dp(N,vector<int>(sum/2+1,-1));
        return dfs(0,N,sum/2,arr,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends