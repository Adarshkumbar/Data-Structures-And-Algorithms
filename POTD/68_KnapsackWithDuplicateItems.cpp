//                  Knapsack with Duplicate Items
//  medium
/*
Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Example 1:

Input: 
N = 2
W = 3
val = {1, 1}
wt = {2, 1}
Output: 
3
Explanation: 
1.Pick the 2nd element thrice.
2.Total profit = 1 + 1 + 1 = 3. Also the total weight = 1 + 1 + 1  = 3 which is <= 3.
Example 2:

Input: 
N = 4
W = 8
val[] = {6, 1, 7, 7}
wt[] = {1, 3, 4, 5}
Output: 
48
Explanation: 
The optimal choice is to pick the 1st element 8 times.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
        int dp[1001][1001];
        int solve(int N, int W, int val[], int wt[]){
            if(N==0 || W==0) 
                return 0;
            if(dp[N][W]!=-1) 
                return dp[N][W];
            if(wt[N-1]<=W){
                return dp[N][W]=max({val[N-1]+solve(N, W-wt[N-1], val, wt), solve(N-1, W, val, wt)});
            }
            else 
                return dp[N][W]=solve(N-1, W, val, wt);
        }
        int knapSack(int N, int W, int val[], int wt[]){
            memset(dp,-1,sizeof(dp));
            return solve(N,W,val,wt);
        }
};

int main(){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    return 0;
}