//                  Stickler Thief
/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. ith house has a[i] amount of money present in it.

Example 1:

Input:
n = 5
a[] = {6,5,5,7,4}
Output: 
15
Explanation: 
Maximum amount he can get by looting 1st, 3rd and 5th house. Which is 6+5+4=15.
Example 2:

Input:
n = 3
a[] = {1,5,3}
Output: 
5
Explanation: 
Loot only 2nd house and get maximum amount of 5.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
//   solving using dp and memoisation
    int solve(int i , int arr[], int n , int dp[]){
        //  Base Case
        if( i >= n )  // out of arr
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        
        //  2 opts rob or not rob
        int op1 = arr[i] + solve(i+2 , arr, n , dp); 
        int op2 = solve(i+1 , arr, n , dp);
        
        return dp[i] = max(op1, op2);
    }
    int FindMaxSum(int a[], int n)
    {
        //  creating dp arr for memoisation
        int dp[n];
        //  initialisin with -1
        for( int i = 0 ; i < n ; i++){
            dp[i]  = -1;
        }
    
        return solve( 0 , a, n , dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends