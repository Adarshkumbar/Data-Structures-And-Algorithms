//                      Shuffle integers
//  medium - recursion
/*
Given an array arr of n elements in the following format {a1, a2, a3, a4, ... , an/2, b1, b2, b3, b4, ... , bn/2}, the task is 
shuffle the array to {a1, b1, a2, b2, a3, b3, ... , an/2, bn/2} without using extra space.
Note that n is even.

Example 1:

Input: 
n = 4, arr = {1, 2, 9, 15}
Output:  
1 9 2 15
Explanation: 
a1=1, a2=2, b1=9, b2=15. So the final array will be: a1, b1, a2, b2 = {1,9,2,15}.

Example 2:

Input: 
n = 6 arr = {1, 2, 3, 4, 5, 6} 
Output: 
1 4 2 5 3 6
*/ 
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:

    void solve(int arr[] , int i , int j , int n ){
        //  base case
        if( n <= 0 )
            return ;
        // storing values for ith and jth index
        int a = arr[i];
        int b = arr[j];
        //  recursive call
        solve( arr , i-1 , j-1 , n-2 );
        
        arr[n-2] = a;
        arr[n-1] = b; 
    }
    
	void shuffleArray(int arr[],int n)
	{
	    int i=n/2-1;
	    int j=n-1;
	    solve(arr,i,j,n);
	}

};

//{ Driver Code Starts.


int main() 
{
    int n;
	cin>>n;
	int a[n] ;
	for(int i=0;i<n;i++)
	{
	    cin>>a[i];
	}
    Solution ob;
    ob.shuffleArray(a, n);
	for (int i = 0; i < n; i++) 
		cout << a[i] << " ";

	cout << "\n";
    return 0;
}