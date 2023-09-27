//                      Find the closest pair from two arrays (easy)
/*
Given two sorted arrays arr and brr and a number x, 
find the pair whose sum is closest to x and the pair has an element from each array.
 In the case of multiple closest pairs return any one of them.
 Note: Can return the two numbers in any manner.
 
Example 1:Input : N = 4, M = 4arr[ ] = {1, 4, 5, 7}brr[ ] = {10, 20, 30, 40} X = 32 Output : 1, 30 
Explanation:The closest pair whose sum is closestto 32 is {1, 30} = 31.
 
 
Example 2:Input : N = 4, M = 4arr[ ] = {1, 4, 5, 7}brr[ ] = {10, 20, 30, 40}X = 50 Output : 7, 40 
Explanation: The closest pair whose sum is closestto 50 is {7, 40} = 47.
*/ 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
 public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        vector<int> values(2,0);
        int i=0;
        int j=m-1;
        int ans=INT_MAX;
        int sum=arr[0]+brr[m-1];
        while(i<n && j>=0)
        {
            sum=arr[i]+brr[j];
            if(ans>abs(sum-x))
            {
                ans=abs(sum-x);
                values[0]=arr[i];
                values[1]=brr[j];
            }
            
            if(sum<=x)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return values;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends